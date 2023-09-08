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
### Multiple applications may share a DLL. Windows tracks the number of applications using each DLL and will only remove the DLL from system memory when it is no longer required. 

## What is **DLL**

### Dynamic Link Libraries are like exe but they are not directly executable. They are similar to .so files in Linux/Unix. That is to say, DLLs are MS's implementation of shared libraries. 

### DLLs are so much like an exe that the file format itself is the same. Both exe and dlls are based on the portable executable file format. dlls can also contain com components and .NET libraries. 

