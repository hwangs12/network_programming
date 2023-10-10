/* Game players will connect here to play tic tac toe */

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    // Create a socket
    /* https://github.com/openbsd/src/blob/master/sys/sys/socket.h */
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        cerr << "Can't create a socket!";
        return -1;
    }
    // Bind the socket to a IP/port
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    // htons translates a short integer from host byte order to network byte order. The unsigned short integer to be put into network byte order. Is typed to the unsigned short integer to be put into network byte order.
    // what is a short integer? just a not long one.
    // what byte order are there? little endian and big endian. big value in low addr is little endian vice versa.
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr); // 127.0.0.1

    if (::bind(listening, (sockaddr *)&hint, sizeof(hint)) == -1)
    {
        cerr << "Can't bind to IP/port";
        return -2;
    }

    // Mark the socket for listening in
    if (listen(listening, SOMAXCONN) == -1)
    {
        cerr << "Can't listen!";
        return -3;
    }

    // Accept a call
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    char host[NI_MAXHOST];
    char svc[NI_MAXSERV];

    int clientSocket = accept(listening, (sockaddr *)&client, &clientSize);

    if (clientSocket == -1)
    {
        cerr << "Problem with client connecting!";
        return -4;
    }
    // Close the listening socket
    close(listening);

    memset(host, 0, NI_MAXHOST);
    memset(svc, 0, NI_MAXSERV);

    int result = getnameinfo((sockaddr *)&client, sizeof(client), host, NI_MAXHOST, svc, NI_MAXSERV, 0);

    if (result)
    {
        cout << host << " connected on " << svc << endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on " << ntohs(client.sin_port) << endl;
    }
    // While receiving display message, echo message
    char buf[4096];
    // send the client the board
    char *buf2 = "message sent";
    while (true)
    {
        // clear the buffer
        memset(buf, 0, 4096);
        memset(buf2, 0, 4096);
        // wait for a message
        int bytesRecv = recv(clientSocket, buf, 4096, 0);
        if (bytesRecv == -1)
        {
            cerr << "There was a connection issue" << endl;
            break;
        }

        if (bytesRecv == 0)
        {
            cout << "The client disconnected" << endl;
            break;
        }

        // display message
        cout << "Received: " << string(buf, 0, bytesRecv) << endl;

        // resend message
        send(clientSocket, buf, bytesRecv + 1, 0);
        send(clientSocket, buf2, strlen(buf2), 0);
    }

    // Close socket
    close(clientSocket);

    return 0;
}