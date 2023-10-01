#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT (7777)
#define BUFF_SIZE (1024)
#define QUEUE_LIMIT (1)

int main()
{
    int serverSocket;
    struct sockaddr_in serverAddr;

    struct sockaddr_in clientAddr;
    unsigned int clientAddrLength;

    char buff[BUFF_SIZE];

    printf("Server start\n");
    /* OPEN SOCKET */
    /* ---------------------- */
    if ((serverSocket = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
    {
        printf("socket() failed.\n");
        return -1;
    }
    /* ---------------------- */

    memset(&serverAddr, 0x00, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);
    /* BIND */
    /* ---------------------- */
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        printf("bind() failed.\n");
        return -2;
    }
    /* ---------------------- */

    printf("    Waiting..\n");

    /* READ/WRITE */
    /* ---------------------- */
    clientAddrLength = sizeof(clientAddr);
    recvfrom(serverSocket, buff, BUFF_SIZE, 0, (struct sockaddr *)&clientAddr, &clientAddrLength);
    /* ---------------------- */

    printf("    Recv data: %s\n", buff);

    close(serverSocket);

    printf("End.\n");

    return 0;
}