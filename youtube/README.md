## [youtube on socket programming](https://www.youtube.com/watch?v=gntyAFoZp-E)

### Starting with illustration
- Word for word: the listening socket sees some client that wants to make a connection. It accepts it by creating a new socket. 

## Socket
### The socket function creates a socket that is bound to a specific transport service provider
### af: The address family specification (AF_INET for UDP or TCP),
### type: The type specification for the new socket (SOCK_STREAM, SOCK_DGRAM)
### protocol: The protocol to be used (IPPROTO_TCP for TCP)

## Deregister Winsock2 DLL
### The WSACleanup function terminates use of the Winsock 2 DLL
### The return value is zero if the operation was successful. Otherwise, the value SOCKET_ERROR is returned
### ```int WSACleanup(void)```
### When it has completed the use of Windows Sockets, the application or DLL must call WSACleanup to deregister itself from a Windows Sockets.
### Multiple applications may share a DLL. Windows tracks the number of applications using each DLL and will only remove the DLL from system memory wen it is no longer required. 
