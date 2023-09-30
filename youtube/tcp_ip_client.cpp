/* link: https://www.youtube.com/watch?v=ocpqxQRnPRs */

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT (80)
#define SERVER_IP ("142.250.9.101")
#define BUFF_SIZE (1024)

int main()
{
    int clientSocket;
    struct sockaddr_in serverAddr;
    char *MSG = "GET / HTTP/1.1\r\n\r\n";
    char buff[BUFF_SIZE];

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
    recv(clientSocket, buff, BUFF_SIZE, 0);

    printf("%s\n", buff);

    close(clientSocket);
    printf("End. \n");
    return 0;
};
