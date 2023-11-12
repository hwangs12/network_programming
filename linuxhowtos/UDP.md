```cpp
fromlen = sizeof(struct sockaddr_in);
while (1)
{
  n = recvfrom(sock,buf,1024,0,(struct sockaddr *)&from,&fromlen);
  if (n < 0) error("recvfrom");
```

Servers using datagram sockets do not use the listen() or the accept() system calls. After a socket has been bound to an address, the program calls recvfrom() to read a message. This call will block until a message is received. The recvfrom() system call takes six arguments. The first three are the same as those for the read() call, the socket file descriptor, the buffer into which the message will be read, and the maximum number of bytes. The fourth argument is an integer argument for flags. This is ordinarily set to zero. The fifth argument is a pointer to a sockaddr_in structure. When the call returns, the values of this structure will have been filled in for the other end of the connection (the client). The size of this structure will be in the last argument, a pointer to an integer. This call returns the number of bytes in the message. (or -1 on an error condition)