/* UDP program flow */

/**
 * UDP client must know the address of the remote UDP peer
 * UDP client uses the getaddrinfo() function to resolve the address into a struct addrinfo structure.
 * Once this is done, the client creates a socket of the proper type.
 * The client can then call sendto() to send the first packet.
 * The client can continue to call sendto() and recvfrom() on the socket to send and receive additional packets.
 * The UDP client cannot receive data first, as the remote peer would have no way of knowing where to send
 * data without receiving data from the client first.
 * This is different from TCP, where a connection is established with a handshake.
 * In TCP, either the client or server can send the first application data.
 *
 * A UDP server listens for connections from a UDP client.
 * This server should initialize struct addrinfo structure with the proper listening IP address and port number.
 * The getaddrinfo() function can be used to do this in a protocol-independent way.
 * The server then creates a new socket with socket() and binds it to the listening IP address
 * and port number using bind().
 * At this point, the server can call recvfrom(), which causes it to block until it receives data from UDP client.
 * After the first data is received, the server can reply with sendto()
 * or listen for more data with recvfrom().
 */