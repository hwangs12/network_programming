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



