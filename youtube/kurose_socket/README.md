socket programming
goal: learn how to build client server applications that communicate using sockets

application ->

socket is the door between application process and end to end transport protocol

socket programming
two socket types for two transport services:
udp: unreliable datagram
tcp: reliable, byte stream-oriented

application example:
1. client reads a line of chars from its keyboard and sends data to server

2. server receives the data and converts characters to uppercase

3. server sends modified data to client

4. client receives modified data and displays line on its screen. 

# socket programming with udp
UDP: no "conenction" between client adn server:
- no handshaking before sending data
- sender explicitly attaches ip destiantion address and port number to each packet
- receiver extracts sender ip address and port number from received packet

udp: transmitted data may be lost or received out of order

application viewpoint
- udp provides unreliable transfer of groups of bytes between client and server process

# client/server socket interaction: UDP

- server
create socket, port = x:
serverSocket = socket(AF_INET, SOCK_DGRAM)

- client
create socket:
clientSocket = socket(AF_INET, SOCK_DGRAM)

Create datagram with serverIP address And port=x; send datagram via clientSocket

then server read datagram from serverSocket then write reply to serverSocket specifying client address, and port number

then client read datagram from clientSocket and close clientSocket

Socket programming with tcp
client must contact server
- server process must first be running
- server must have created socket that welcomes client's contact

Client contacts server by:
- Creating TCP socket, specifying IP address, port number of server process
- **when client creates socket**: client TCP establishes connection to server TCP

### Server
- When contacted by client, **server TCP creates new socket** for server process to communicate with that particular client
- allows server to talk with multiple clients
- source port numbers used to distinguish clients 

Application viewpoint
Tcp provides reliable, in-order byte-stream transfer between client and server processes

# Client/server socket interaction: TCP

server (running on hostid) 
- create socket,
port=x, for incoming request
serverSocket = socket()

server then invokes wait for incoming connection request
connectionSocket = serverSocket.accept()

client
- create socket,
connect to hostid, port=x
clientSocket = socket()
then connection is set up 
via transport layer

client send request using clientsocket

server read request from connectionsocket
then write reply to connectionSocket

client read reply from client socket
closed clientsocket

closed serversocket
**server side app uses this newly created socket to accept not the listening socket to communicate with client**






