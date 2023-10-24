```cpp
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
```

The header files are the same as for the server with one addition. The file `netdb.h` defines the structure hostent, which will be used below. 

```cpp
void error(char *msg)
{
    perror(msg);
    exit(0);
}
int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
}
```

The `error()` function is identical to that in the server, as are the variables `sockfd`, `portno`, and `n`. The variable `serv_addr` will contain the address of the server to which we want to connect. It is of type `struct sockaddr_in`.

The variable `server` is a pointer to a structure of type `hostent`. This structure is defined in the header file `netdb.h` as follows:

```cpp
struct hostent
{
    char    *h_name;        /* official name of host */
    char    **h_aliases;    /* alias list */
    int     h_addrtype;     /* host address type */
    int     h_length;       /* length of address */
    char    **h_addr_list;  /* list of addresses from name server */
    #define h_addr  h_addr_list[0]  /* address, for backward compatibility */
};
```

It defines a host computer on the Internet. The mbmers of this structure are:
> `h_name`  Official name of the host.
> `h_aliases`   A zero terminated array of alternate names for the host.
> `h_addrtype`  The type of address being returned; currently always AF_INET;
> `h_length`    The length, in bytes, of the address.
> `h_addr_list` A pointer to a list of network addresses for the named host. Host addresses are returned in network byte order. 

Note that `h_addr` is an alias for the first address in the array of network addresses. 

```cpp
server = gethostbyname(argv[1]);
if (server == NULL)
{
    fprintf(stderr, "ERROR, no such host");
    exit(0);
}
```

The variable `argv[1]` contains the name of a host on the Internet, e.g. `cs.rpi.edu`. The function:

```cpp
struct hostent *gethostbyname(char *name)
```
Takes such a name as an argument and returns a pointer to a `hostent` containing information about that host.

The field `char *h_addr` contains the IP address.

If this structure is NULL, the system could not locate a host with this name. 

In the old days, this function worked by searching a system file called `/etc/hosts` but with the explosive growth of the Internet, it became impossible for system administrators to keep this file current. Thus, the mechanism by which this function works is complex, often involves querying large databases all around the country.

___

```cpp
bzero((char *) &serv_addr, sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
bcopy((char *) server -> h_addr,
        (char *) &serv_addr.sin_addr.s_addr, 
        server -> h_length);
serv_addr.sin_port = htons(portno);
```

This code sets the fields in `serv_addr`. Much of it is the same as in the server. However, because the field `server->h_addr` is a character string, we use the function:

```cpp
void bcopy(char *s1, char *s2, int length)
```

which copies `length` bytes from `s1` to `s2`.

```cpp
if (connect(sockfd, &serv_addr, sizeof(serv_addr)) < 0)
{
    error("ERROR connecting");
}
```

The `connect` function is called by the client to establish a connection to the server. It takes three arguments, the socket file descriptor, the address of the host to which it wants to connect, and the size of this address. This function returns 0 on success and -1 if it fails. 

Notice that the client needs to know the port number of the server, but it does not need to know its own port number. This is typically assigned by the system whe `connect` is called. 

```cpp
printf("Please enter the message: ");
bzero(bufer, 256);
fgets(buffer, 255, stdin);
n = write(sockfd, buffer, strlen(buffer));
if (n < 0)
{
    error("ERROR writing to socket");
}
bzero(buffer, 256);
n = read(sockfd, buffer, 255);
if (n < 0)
{
    error("ERROR reading from socket");
}
printf("%s", buffer);
return 0;
```

The remaining code should be fairly clear. It prompts the user to enter a message, uses `fgets` to read the message from stdin, writes the message to the socket, reads the reply from the socket, and displays this reply on the screen.

