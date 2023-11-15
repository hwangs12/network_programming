/* time_server */

#if defined(_WIN32)
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib");

#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#endif

#if defined(_WIN32)
#define ISVALIDSOCKET(s) ((s) != INVALID_SOCKET)
#define CLOSESOCKET(s) closesocket(s)
#define GETSOCKETERRNO() (WSAGetLastError())

#else
#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETERRNO() (errno)
#endif

#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
#if defined(_WIN32)
    WSADATA d;
    if (WSAStartup(MAKEOWRD(2, 2), &d))
    {
        fprintf(stderr, "Failed to initialize. \n");
        return 1;
    }
#endif

    printf("Configuring local address...\n");
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    struct addrinfo *bind_address;
    getaddrinfo(0, "8080", &hints, &bind_address);

    /* now that we've the local address info, we can create the socket */

    /* It is common to see programs written with socket call first. */
    /* The problem with this is that it makes the program more complicated as the socket family, type, and protocol must be entered multiple times */
    /* Structuring our program as we have here is better. */

    printf("Creating socket...\n");
    SOCKET socket_listen;
    socket_listen = socket(bind_address->ai_family, bind_address->ai_socktype, bind_address->ai_protocol);

    /* Checking socket call was successful */

    if (!ISVALIDSOCKET(socket_listen))
    {
        fprintf(stderr, "socket() failed. (%d) \n", GETSOCKETERRNO());
        return 1;
    }

    /* After the socket is created successfully, we can call bind() to associate it with our address from getaddrinfo() */
    /* bind returns unsigned int if it fails */

    printf("Binding socket to local address...\n");
    if (bind(socket_listen, bind_address->ai_addr, bind_address->ai_addrlen))
    {
        fprintf(stderr, "bind() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    freeaddrinfo(bind_address);

    /* Once the socket has been created and bound to a local address, we can cause it to start listening for connections with the listen() function: */

    printf("listening...\n");
    if (listen(socket_listen, 10) < 0)
    {
        fprintf(stderr, "listen() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }

    /* to be continued... */
}