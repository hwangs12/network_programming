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

