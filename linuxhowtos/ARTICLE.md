# [Sockets](https://www.linuxhowtos.org/C_C++/socket.htm)

## The client server model

Most interprocess communication uses the *client server* model. 

These terms refer to the two processes which will be communicating with each other. 

One of the two processes, the *client*, connects to the other process, the *server*, typically to make a request for information.

A good analogy is a person who makes a phone call to another person. 

Notice that the client needs to know of the existence of and the address of the server, but the server does not need to know the address of the client prior to the connection being established. 

The system calls for establishing a connection are somewhat different for the client and the server, but both involve the basic construct of a *socket*.

A socket is one end of an interprocess communication channel. The two processes each establish their own socket. 

The steps involved in establishing a socket on the *client* side are as follows:
1. Create a socket with the socket() system call
2. Connect the socket to the address of the server using the connect() system call
3. Send and receive data. There are a number of ways to do this, but the simplest is to use the read() and write() system calls. 

Links to each functions
### CLIENT SIDE
- [socket()](https://www.linuxhowtos.org/manpages/2/socket.htm)
- [connect()](https://www.linuxhowtos.org/manpages/2/connect.htm)
- [read()](https://www.linuxhowtos.org/manpages/2/read.htm)
- [write()](https://www.linuxhowtos.org/manpages/2/write.htm)

### SERVER SIDE
- [socket()](https://www.linuxhowtos.org/manpages/2/socket.htm)
- [connect()](https://www.linuxhowtos.org/manpages/2/connect.htm)
- [bind()](https://www.linuxhowtos.org/manpages/2/bind.htm)
- [listen()](https://www.linuxhowtos.org/manpages/2/listen.htm)
- [accept()](https://www.linuxhowtos.org/manpages/2/accept.htm)

