## [youtube on socket programming](https://www.youtube.com/watch?v=gntyAFoZp-E)

### Starting with illustration
- Word for word: the listening socket sees some client that wants to make a connection. It accepts it by creating a new socket. 

### Socket
## The socket function creates a socket that is bound to a specific transport service provider
## af: The address family specification (AF_INET for UDP or TCP),
## type: The type specification for the new socket (SOCK_STREAM, SOCK_DGRAM)
## protocol: The protocol to be used (IPPROTO_TCP for TCP)