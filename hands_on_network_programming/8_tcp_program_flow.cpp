/* HOW TCP PROGRAM WORKS */

/*
 * TCP client program must first know the TCP server's address
 * This is often input by a user
 * In the web browser, server address is directly inputted by the user in the address bar
 * The TCP client takes this address and uses the getaddrinfo() function to resolve it into a struct addrinfo structure.
 * The client then creates a socket using a call to socket().
 * The client then establishes the new TCP connection by calling connect().
 * At this point, the client can freely exchange data using send() and recv().
 *
 * TCP server listens for connections at a particular port number on a particular interface
 * The program must be bound to the listening IP address and port.
 * This is accomplished with a call to bind().
 *
 * The server program then calls listen(), which puts the socket in a state where it listens for new connections.
 * The server can then call accept(), which will wait until a client establishes a connection to the server.
 * When the new connection has been established, accept() returns a new socket.
 * This new socket can be used to exchange data with the client using send() and recv()
 * Meanwhile, the first socket remains listening for new connections,
 * and repeated calls to accept() allow the server to handle multiple clients.
 */