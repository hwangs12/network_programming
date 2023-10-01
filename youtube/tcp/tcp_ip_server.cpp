/* link: https://www.youtube.com/watch?v=ocpqxQRnPRs */

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
    // ok server socket is just an integer
    int serverSocket;
    // sockaddr_in is certain structure
    // should i dig in what it consissts of ? sure
    /*
     *include <netinet/in.h>

    * struct sockaddr_in {
    *     short            sin_family;   // e.g. AF_INET
    *     unsigned short   sin_port;     // e.g. htons(3490)
    *     struct in_addr   sin_addr;     // see struct in_addr, below
    *     char             sin_zero[8];  // zero this if you want to
    * };
*
    * struct in_addr {
    *     unsigned long s_addr;  // load with inet_aton()
    * };
     * you can set ip and port here
     * what is sin family
     * what is sin port
     * what does sin stand for
     * what is in_addr struct
     * struct in_addr {
     *  unasigned long s_addr; // load with inet_aton()
     * }
     * what is sin_zero[8]
     * what htons? the htons function takes a 16-bit number in host byte order and returns a 16-bit number in network byte order used in TCP/IP networks
     * where can i see the implementation?
     */
    struct sockaddr_in serverAddr;
    // client socket is also int
    int clientSocket;

    // client socket is also sockaddr_in struct
    struct sockaddr_in clientAddr;

    //
    unsigned int clientAddrLength;
    char buff[BUFF_SIZE];

    printf("Server start\n");

    // further to dig in: what does socket function return - what does it depend on? How does it work?
    if ((serverSocket = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("socket() failed.\n");
        return -1;
    }

    // format data in serverAddr?
    // what really is memset?
    memset(&serverAddr, 0X00, sizeof(serverAddr));
    // both af_inet and pf_inet are for ipv4
    serverAddr.sin_family = AF_INET;
    // using computer's current ip address
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // port opening on 7777.
    serverAddr.sin_port = htons(PORT);

    // BINDING STAGE
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        printf("bind() failed.\n");

        return -2;
    }

    // LISTENING STAGE
    if (listen(serverSocket, QUEUE_LIMIT) < 0)
    {
        printf("listen() failed ");
        return -3;
    }

    printf("    Waiting..\n");

    clientAddrLength = sizeof(clientAddr);

    while (1)
    {
        // LOOP UNTIL SIGNAL RECEIVED
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLength);
        if (clientSocket > 0)
        {
            break;
        }
    }

    // READ WRITE

    printf("    Client is connected.\n");
    recv(clientSocket, buff, BUFF_SIZE, 0);
    printf("    Recv data: %s\n", buff);

    char *MSG_FROM_SERVER = "message from server!";

    if (send(clientSocket, MSG_FROM_SERVER, strlen(MSG_FROM_SERVER), 0) < 0)
    {
        printf("send() failed. \n");
        return -3;
    }
    // CLOSE
    close(clientSocket);
    close(serverSocket);
    printf("End \n");
    return 0;
}