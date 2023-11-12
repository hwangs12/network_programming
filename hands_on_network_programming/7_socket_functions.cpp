/* SOCKET FUNCTIONS */

/* socket() creates and initializes a new socket */

/* bind() associates a socket with a particular local Ip address and port number */

/* listen() is used on the server to cause a TCP socket to listen for new connections. */

/* connect() is used on the client to set the remote address and port. In the case of TCP, it also establishes a connection. */

/* accept() is used on the server to create a new socket for an incoming TCP connection */

/* send() and recv() are used to send and receive data with a socket. */

/* sendto() and recvfrom() are used to send and receive data from sockets without a bound remote address */

/* close() and closesocket() are used to close a socket. In the case of TCP, this also terminates the connection. */

/* shutdown() is used to close one side of a TCP connection. It is useful to ensure an orderly connection teardown. */

/* select() is used to wait for an event on one or more sockets. */

/* getnameinfo() and getaddrinfo() provide a protocol-independent manner of working with hostnames and addresses */

/* setsockopt() is used to change some socket options. */

/* fcntl() and ioctlsocket() are also used to get and set some socket options. */
