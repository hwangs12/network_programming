# SAMPLE CODE

C code for a very simple client and server are provided for you. 
These communicate using stream sockets in the Internet domain.
The code is described in detail below.
However, before you read the descriptions and look at the code, you should compile
and run the two programs to see what they do.

___
[server.cpp](server.cpp)
[client.cpp](client.cpp)
___

Ideally, you should run the client and the server on separate hosts on the Internet. 
Start the server first.
Suppose the server is running on a machine called *cheerios*.
When you run the server, you need to pass the port number in as an argument.
You can choose any number between 2000 and 65535.
If this port is already in use on that machine, the server will tell you this and exit.
If this happens, just choose another port and try again.
If the port is available, the server will block until it receives a connection from the client.
Don't be alarmed if the server doesn't do anything. 

