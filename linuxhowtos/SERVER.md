This is a server.cpp explanation

## `#include <stdio.h>`

#### This header file contains declarations used in most input and output and is typically included in all C programs.

## `#include <sys/types.h>`

#### This header file contains definitions of a number of data types used in system calls. These types are used in the next two include files. 

## `#include <sys/socket.h>`

#### The header file socket.h includes a number of definitions of structures needed for sockets. 

## `#include <netinet/in.h>`

#### The header file in.h contains constants and structures needed for internet domain addresses. 

___

```cpp
void error(char *msg)
{
    perror(msg);
    exit(1);
}
```

This function is called when a system call fails. It displays a message about the error on stder and then aborts the program. The perror man page gives more information. 
___

```cpp
int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, n;
```
`sockfd` and `newsockfd` are file descriptors, i.e. array subscripts into the file descriptor table. These two variables store the values returned by the socket system call and the accept system call. 

`portno` stores the port number on which the server accepts connections. 

`clilen` stores the size of the address of the client. This is needed for the accept system call. 

`n` is the return value for the `read()` and `write()` calls; i.e. it contains the number of *characters* read or written. 
___

```cpp
char buffer[256];
```

The server reads characters from the socket connection into this buffer
___

```cpp
struct sockaddr_in serv_addr, cli_addr;
```

A `sockaddr_in` is a structure containing an internet address. This structure is defined in `netinet/in.h`.

Here is the definition:

```cpp
struct sockaddr_in
{
    short   sin_family; // must be AF_INET
    u_short sin_port;
    struct  in_addr sin_addr;
    char    sin_zero[8]; // not used, must be zero
}
```

An `in_addr` structure, defined in the same header file, contains only one field, a unsigned long called `s_addr`.

The variable `serv_addr` will contain the address of the server, and `cli_addr` will contain the address of the client which connects to the server. 
___

```cpp
if (argc < 2)
{
    fprintf(stderr, "ERROR, no port provided");
    exit(1);
}
```

The user needs to pass in the port number on which the server will accept connections as an argument. This code displays an error message if the user fails to do this. 
___

```cpp
sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd < 0)
{
    error("ERROR opening socket");
}
```

The `socket()` system call creates a new socket. It takes three arguments. The first is the address domain of the socket. 

Recall that there are two possible address domains, the unix domain for two processes which share a common file system, and the Internet domain for any two processes which share a common file system, and the Internet domain for any two hosts on the Internet. The symbol constant AF_UNIX is used for the former, and AF_INET for the latter (there are actually many other options which can be used here for specialized purposes).

The second argument is the type of socket. Recall that there are two choices here, a stream socket in which characters are read in a coninuous stream as if from a file or pipe, and a datagram socket, in which messages are read in chunks. The two symbolic constants are `SOCK_STREAM` and `SOCK_DGRAM`.

The third argument is the protocol. If this argument is zero (and it always should be except for unusual circumstances), the operating system will choose the most appropriate protocol. It will choose TCP for stream sockets and UDP for datagram sockets. 

The socket system call returns an entry into the file descriptor table (i.e. a small integer). This value is used for all subsequent references to this socket. If the socket call fails, it returns -1. 

In this case the program displays an error message and exits. However, this system call is unlikely to fail.

This is a simplified description of the socket call; there are numerous other choices for domains and types, but these are the most common.

```cpp
bzero((char *) &serv_addr, sizeof(serv_addr));
```

The function bzero() sets all values in a buffer to zero. It takes two arguments, the first is a pointer to the buffer and the second is the size of the buffer. Thus, this line initializes serv_addr to zeros. 

```cpp
portno = atois(argv[1]);
```

The port number on which the server will listen for connections is passed in as an argument, and this statement uses the atoi() function to convert this from a string of digits to an integer.

```cpp
serv_addr.sin_family = AF_INET;
```

The variable `serv_addr` is a structure of type `struct sockaddr_in`. This structure has four fields. The first field is `short sin_family` which contains a code for the address family. It should always be set to the symbolic constant AF_INET.

```cpp
serv_addr.sin_port = htons(portno);
```

The second field of `serv_addr` is `unsigned short sin_port`, which contains the port number. However, instead of simply copying the port number to this field, it is necessary to convert this to network byte order using the function `htons()` which converts a port number in host byte order to a port number in network byte order. 

```cpp
if (bind(sockfd, (strct sockaddr *) &serv_addr, error("ERROR on binding")));
```

The `bind()` system call binds a socket to an address, in this case the address of the current host and port number on which the server will run. It takes three arguments, the socket file descriptor, the address to which is bound, and the size of the address to which it is bound. The second argument is a pointer to a structure of type `sockaddr`, but what is passed in is a structure of type `sockaddr_in`, and so this must be cast to the correct type. This can failf or a number of reasons, the most obvious being that this socket is already in use on this machine. 

```cpp
listen(sockfd, 5);
```

The `listen` system call allows the process to listen on the socket for connections. The first argument is the socket file descriptor, and the second is the size of the backlog queue, i.e., the number of connections that can be waiting while the process is handling a particular connection. this should be set to 5, the maximum size permitted by most systems. If the first argument is a valid socket, this call cannot fail, and so the code doesn't check for errors.

```cpp
clilen = sizeof(cli_addr);
newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
if (newsockfd < 0)
{
    error("ERROR on accept");
}
```

The `accept()` system call causes the process to block until a client connects to the server. Thus, it wakes up the process when a connection from a client has been successfully established. It returns a new file descriptor, and all communication on this connection should be done using the new file descriptor. The second argument is a reference pointer to the address of the client on the other end of the connection, and the third argument is the size of this structure. 

```cpp
bzero(buffer, 256);
n = read(newsockfd, buffer, 255);
if (n < 0)
{
    error("ERROR reading from socket");
    printf("Here is the message: %s", buffer);
}
```

Note that we would only get to this point after a client has successfully connected to our server. This code initializes the buffer using the `bzero()` function, and then reads from the socket. Note that the read call uses the new file descriptor, the one returned by `accept()`, not the original file descriptor returned by `socket()`. Note also that the `read()` will block until there is something for it to read in the socket, i.e. after the client has executed a `write()`. 

It will read either the total number of characters in the socket or 255, whichever is less, and return the number of characters read. 

```cpp
n = write(newsockfd, "I got your message", 18);
if (n < 0)
{
    error("ERROR writing to socket");
}
```

Once a connection has been established, both ends can both read and write to the connection. Naturally, everything written by the client will be read by the server, and everything written by the server will be read by the client. This code simply writes a short message to the client. The last argument of write is the size of the message. 









