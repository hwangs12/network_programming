#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP ("127.0.0.1")
#define SERVER_PORT (7777)

int main()
{
    int clientSocket;
    struct sockaddr_in serverAddr;
    char *MSG = "Hello~!";

    printf("Client start\n");

    /* OPEN SOCKET */
    /* ------------------ */
    if ((clientSocket = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
    {
        printf("socket() failed.\n");
        return -1;
    }
    /* ------------------ */

    memset(&serverAddr, 0x00, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serverAddr.sin_port = htons(SERVER_PORT);

    /* READ/WRITE */
    /* ------------------ */
    if (sendto(clientSocket, MSG, strlen(MSG), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        printf("send() failed.\n");
        return -3;
    }
    /* ------------------ */

    printf("    Sending completed.\n");

    close(clientSocket);

    printf("End.\n");

    return 0;
}