/* link: https://www.youtube.com/watch?v=ocpqxQRnPRs */

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT (7777)
#define SERVER_IP ("127.0.0.1")

int main()
{
    int clientSocket;
    struct sockaddr_in serverAddr;
    char *MSG = "Hello~~~~!";

    printf("Client start \n");

    if ((clientSocket = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("socket() failed.\n");
        return -1;
    }

    memset(&serverAddr, 0X00, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serverAddr.sin_port = htons(SERVER_PORT);

    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        printf("connect() failed. \n");
        return -2;
    };

    if (send(clientSocket, MSG, strlen(MSG), 0) < 0)
    {
        printf("send() failed. \n");
        return -3;
    }

    printf("    Sending completed.\n");
    close(clientSocket);
    printf("End. \n");
    return 0;
};
