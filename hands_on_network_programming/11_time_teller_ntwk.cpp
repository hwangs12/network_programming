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

    /* After the socket has begun listening for connections, we can accept any incoming connection with the accept() function */

    /* Inside accept there are a few functions. */
    /* When accept is called, it will block your program until a new connection is made */
    /* In other words, your program will sleep until a connection is made to the listening socket.  */
    /* When the new connection is made, accept() will create a new socket for it.  */
    /* Your original socket continues to listen for new connections, but the new socket returned by accept() can be used to send and receive data over the newly established connection.  */
    /* accept also fills in address info of the client that connected.  */

    printf("Waiting for connection...\n");
    struct sockaddr_storage client_address;
    socklen_t client_len = sizeof(client_address);
    SOCKET socket_client = accept(socket_listen, (struct sockaddr *)&client_address, &client_len);
    if (!ISVALIDSOCKET(socket_client))
    {
        fprintf(stderr, "accept() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }

    /* TCP connection has been established to a remote client. We can print the client's address to the console. */

    printf("Client is connected... ");
    char address_buffer[100];
    getnameinfo((struct sockaddr *)&client_address, client_len, address_buffer, sizeof(address_buffer), 0, 0, NI_NUMERICHOST);
    printf("%s\n", address_buffer);

    /* As we are programming a web server, we expect the client (for exapmle, web browser) to send us an HTTP request. We read this request using the recv() function */

    /* check recv() > 0 in production */

    printf("Reading request...\n");
    char request[1024];
    int bytes_received = recv(socket_client, request, 1024, 0);
    printf("Received %.*s bytes.\n", bytes_received, request);

    /* Now that the web browser has sent its request, we can send our response back. */

    printf("Sending response...\n");
    const char *response =
        "HTTP/1.1 200 OK \r\n"
        "Connection: close\r\n"
        "Content-Type: text/plain\r\n\r\n"
        "Local time is: ";
    int bytes_sent = send(socket_client, response, strlen(response), 0);
    printf("Sent %d of %d bytes.\n", bytes_sent, (int)strlen(response));

    /* Getting local time */

    time_t timer;
    time(&timer);
    char *time_msg = ctime(&timer);
    bytes_sent = send(socket_client, time_msg, strlen(time_msg), 0);
    printf("Sent %d of %d bytes.\n", bytes_sent, (int)strlen(time_msg));

    /* Close the connection */
    printf("Closing connection...\n");
    CLOSESOCKET(socket_client);

    /* Close the listening socket and terminate program */
    printf("Closing listening socket...\n");
    CLOSESOCKET(socket_listen);

#if defined(_WIN32)
    WSACleanup();
#endif

    printf("Finished.\n");
    return 0;
}