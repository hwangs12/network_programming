# WHAT DOES EACH LINE DO?
```cpp
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
```
`iostream` is for input and output
`sys/types.h` is a collection of typedef symbols and structures
`unistd.h` is a header file that provides access to the POSIX operating system API. close function comes from this. 
`sys/socket.h` contains sockets definitions. The structure sockaddr_storage is exposed by defining the feature test macro
`netbd.h` makes available the type in_port_t and the type in_addr_t as defined in the description of netinet/in.h
`arpa/inet.h`