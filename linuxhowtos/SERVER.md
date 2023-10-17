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












