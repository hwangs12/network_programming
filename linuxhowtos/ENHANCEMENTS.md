## Enhancements to the server code

`server.cpp` sample code has the limitation that it only handles one connection, and then dies. A "real world" server should run indefinitely and should have the capability of handling a number of simultaneous connections, each in its own process. This is typically done by forking off a new process to handle each new connection.

The following code has a dummy function called `dostuff(int sockfd)`.

This function will handle the connection after it has been established and provide whatever services the client requests. As we saw above, once a connection is established, both ends can use `read` and `write` to send information to the other end, and the details of the information passed back and forth do not concern us here.

To write a "real world" server, you would make essentially no changes to the `main()` function, and all of the code which provided the service would be in `dostuff()`.

To allow the server to handle multiple simultaneous connections, we make the following changes to the code:

1. Put the accept statement and the following code in an infinite loop.
2. After a connection is established, call `fork()` #### to create a new process.
3. The child process will close `sockfd####` and call `#dostuff#####`, passing the new socket file descriptor as an argument. When the two processes have completed their conversation, as indicated by `dostuff()####` returning, this process simply exits. 
4. The parent process closes `newsockfd####`. Because all of this code is in an infinite loop, it will return to the accept statement to wait for the next connection.

Here is the code.
```cpp
while (1)
{
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
    {
        error("ERROR on accept");
        pid = fork();
        if (pid < 0)
        {
            error("ERROR on fork");
        }
        if (pid == 0)
        {
            close(sockfd);
            dostuff(newsockfd);
            exit(0);
        }
        else
        {
            close(newsockfd);
        }
    } /* end of while */
}
```