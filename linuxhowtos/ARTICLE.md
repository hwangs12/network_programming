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

The steps involved in establishing a socket on the *server* side are as follows:
1. Create a socket with the socket() system call
2. Bind the socket to an address using the bind() system call. For a server socket on the Internet, an address consists of a port number on the host machine.
3. Listen for connections with the listen() system call
4. Accept a connection with the accept() system call. This call typically blocks until a client connects with the server.
5. Send and receive data.

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

## Socket Types

When a socket is created, the program has to specify the *address domain* and the *socket type*. **Two processes can communicate with each other only if their sockets are of the same type and in the same domain.**

There are two widely used address domains, the *unix* domain, in which two processes which share a common file system communiate, and the *Internet domain*, in which two processes running on any two hosts on the Internet communicate. Each of these has its own address format.

The address of a socket in the Unix domain is a character string which is basically an entry in the file system.

The address of a socket in the Internet domain consists of the Internet

