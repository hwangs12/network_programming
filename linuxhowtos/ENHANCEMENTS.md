## Enhancements to the server code

`server.cpp` sample code has the limitation that it only handles one connection, and then dies. A "real world" server should run indefinitely and should have the capability of handling a number of simultaneous connections, each in its own process. This is typically done by forking off a new process to handle each new connection.

The following code has a dummy function called `dostuff(int sockfd)`.

This function will handle the connection after it has been established and provide whatever services the client requests. As we saw above, once a connection is established, both ends can use `read` and `write` to send information to the other end, and the details of the information passed back and forth do not concern us here.

To write a "real world" server, you would make essentially no changes to the `main()` function, and all of the code which provided the service would be in `dostuff()`.