# [link](https://docs.freebsd.org/en/books/developers-handbook/sockets/)

## Chapter 7. Sockets

### BSD sockets take interprocess communications to new level (let's see)

### Motivation: Not only do these processes not have to run on the same machine, they do not have to run under the same operating system. 

### your freebsd software can smoothly cooperate with a program running on a macintosh, sun workstation and windows all connected with an ethernet-based local area network. 

### Networking and Diversity

### writing word to word as they are interesting...

#### To inform our software how to handle the raw data, it is encoded as PNG file. It could be a GIF, or a JPEG, but it is a PNG.

#### And PNG is a protocol. At this point, I can hear some of you yelling, "No, it is not! It is a file format!"

#### Well, of course it is a file format. But from the perspective of data communications, a file format is a protocol: The file structure is a language, a terse one at that, communicating to our process how the data is organized. Ergo, it is a protocol. 

#### Alas, if all we received was the PNG file, our software would be facing a serious problem: How is it supposed to know the data is representing an image, as opposed to some text, or perhaps a sound, or what not? 

#### Secondly, how is it supposed to know the image is in the PNG format as opposed to GIF, or JPEG, or some other image format? 

#### To obtain that information, we are using anther protocol: HTTP. This protocol can tell us exactly that the data represents an image, and that it usees the PNG protocol. It can also tell us some other things, but let us stay focused on protocol layers here. 

#### So, now we have some data wrapped in the PNG protocol, wrapped in the HTTP protocol. How did we get it from the server?

#### By using TCP/IP over Ethernet, that is how. Indeed, that is three more protocols. Instead of continuing inside out, I am now going to talke about Ethernet, simply because it is easier to explain the rest that way. 

#### Ethernet is an interesting system of connectin computers in a local area network. Each computer has a network interface card, which has a unique 48bit ID called its address. No two Ethernet NICs in the world have the same address. 

#### These NICs are all connected with each other. Whenever one computer wants to communicate with another in the same Ethernet LAN, it sends a message over the network. Every NIC sees the message. But as part of the Ethernet protocol, the data contains the address of the destination NIC. So, only one of all the network interface cards will pay attention to it, the rest will ignore it. 

#### But not all computers are connected to the same network. Just because we have received the data over our Ethernet does not mean it originated in our own local area network. It could have come to us from some other network (which may not even be Ethernet based) connected with our own network via the Internet. 

#### All data is transferred over the internet using ip, which stands for internet protocol. its basic role is to let us know where in the world the data has arrived from, and where it is supposed to go to. It does not guarantee we will receive the data, only that we will know where it came from if we do receive it. 

#### TCP asks the sender to resend any lost data and that places it all into the proper order. 

#### Luckily for you, you are not supposed to handle it all. You are supposed to handle some of it, but not all of it. Specifically, you need not worry about the physical connection. Nor do you need to handle the internet protocol, or the transmission control protocol. 

#### In other words, you do not have to receive the data from the other computer. Well, you do have to ask for it, but that is almost as simple as opening a file.

#### Once you have received the data, it is up to you to figure out what to do with it. In our case, you would need to understand the HTTP protocol and the PNG file structure. 

#### To use an analogy, all the internetworking protocols become gray area: Not so much because we do not understand how it works, but because we are no longer concerned about it. The sockets interface takes care of this gray area for us:

#### We only need to understand any protocols that tell us how to interpret the data, not how to receive it from another process, nor how to send it to another process. 

#### BSD sockets are built on the basic UNIX model: Everything is a file. In our example, then, sockets would let ue receive an HTTP file, so to speak. It would then be up to us to extract the PNG file from it. 

#### Due to the complexity of internetworking, we cannot just use the open system call, or the open() C function. Instead, we need to take several steps to "opening" a socket. 

#### Once we do, however, we can start treating the socket the same way we treat any file descriptor: We can read from it, write to it, pipe it, and, eventually, close it. 

#### while freebsd offers different functions to work with sockets, we only need four to "open" a socket. and in some cases we only need two.

#### the client-server difference - typically, one of the ends of a socket-based data communication is a server, the other is a client. 

#### the common elements: the one function used by both, clients and servers, is socket. it is declared this way.

```
int socket(int domain, int type, int protocol);
```

#### the return value is of the same type as that of open, an integer. freebsd allocates its value from the same pool as that of file handles. that is what allows sockets to be treated the same way as files. 

#### the `domain` argument tells the system what protocol family you want it to use. many of them exist, some are vendor specific, others are very common. theya re declared in sys/socket.h

#### use pf_inet for udp, tcp and other internet protocols

#### the domain argument tells the system what protocol family you want it to use. Many of them exist, some are vendor specific, others are very common. They are declared in sys/socket.h

#### PF_INET for UDP, TCP and other Internet protocols (IPv4).

#### Five values are defined for the `type` argument, again, in sys/socket.h/ All of them start with "SOCK_". The most common one is SOCK_STREAM, which tells the system you are asking for a reliable stream delivery service

#### if you asked for SOCK_DGRAM, you would be requesting a connectionless datagram delivery service. 

#### If you wanted to be in charge of the low-level protocols such as IP, or even tnetwork interfaces, you would need to specify SOCK_RAW. 

#### Finally, the `protocol` argument depends on the previous two arguments, and is not always meaningful. In that case, use 0 for its value. 

### sockaddr

#### Various functions of the sockets family expect the address of a small area of the memory. The various C declarations in the sys/socket.h refer to it as `struct sockaddr`. This structure is declared in the same file: 

```
/*
 * Structure used by kernel to store most
 * addresses.
 */
struct sockaddr {
	unsigned char	sa_len;		/* total length */
	sa_family_t	sa_family;	/* address family */
	char		sa_data[14];	/* actually longer; address value */
};
#define	SOCK_MAXADDRLEN	255		/* longest possible addresses */
```

#### Please note the vagueness with which the sa_data field is declared, just as an array of 14 bytes, with the comment hinting there can be more than 14 of them. 

#### This vagueness is quite deliberate. Sockets is a very powerful interface. While most people perhaps think of it as nothing more than the internet interface- and most applications probably use it for that nowadays-sockets can be used for just about any kind of interprocess communications, of which the internet (or, more precisely, IP)  is only one. 

#### The sys/socket.h refers to the various types of protocols sockets will handle as address families, and lists them right before the definition of `sockaddr`:

```
/*
 * Address families.
 */
#define	AF_UNSPEC	0		/* unspecified */
#define	AF_LOCAL	1		/* local to host (pipes, portals) */
#define	AF_UNIX		AF_LOCAL	/* backward compatibility */
#define	AF_INET		2		/* internetwork: UDP, TCP, etc. */
#define	AF_IMPLINK	3		/* arpanet imp addresses */
#define	AF_PUP		4		/* pup protocols: e.g. BSP */
#define	AF_CHAOS	5		/* mit CHAOS protocols */
#define	AF_NS		6		/* XEROX NS protocols */
#define	AF_ISO		7		/* ISO protocols */
#define	AF_OSI		AF_ISO
#define	AF_ECMA		8		/* European computer manufacturers */
#define	AF_DATAKIT	9		/* datakit protocols */
#define	AF_CCITT	10		/* CCITT protocols, X.25 etc */
#define	AF_SNA		11		/* IBM SNA */
#define AF_DECnet	12		/* DECnet */
#define AF_DLI		13		/* DEC Direct data link interface */
#define AF_LAT		14		/* LAT */
#define	AF_HYLINK	15		/* NSC Hyperchannel */
#define	AF_APPLETALK	16		/* Apple Talk */
#define	AF_ROUTE	17		/* Internal Routing Protocol */
#define	AF_LINK		18		/* Link layer interface */
#define	pseudo_AF_XTP	19		/* eXpress Transfer Protocol (no AF) */
#define	AF_COIP		20		/* connection-oriented IP, aka ST II */
#define	AF_CNT		21		/* Computer Network Technology */
#define pseudo_AF_RTIP	22		/* Help Identify RTIP packets */
#define	AF_IPX		23		/* Novell Internet Protocol */
#define	AF_SIP		24		/* Simple Internet Protocol */
#define	pseudo_AF_PIP	25		/* Help Identify PIP packets */
#define	AF_ISDN		26		/* Integrated Services Digital Network*/
#define	AF_E164		AF_ISDN		/* CCITT E.164 recommendation */
#define	pseudo_AF_KEY	27		/* Internal key-management function */
#define	AF_INET6	28		/* IPv6 */
#define	AF_NATM		29		/* native ATM access */
#define	AF_ATM		30		/* ATM */
#define pseudo_AF_HDRCMPLT 31		/* Used by BPF to not rewrite headers
					 * in interface output routine
					 */
#define	AF_NETGRAPH	32		/* Netgraph sockets */
#define	AF_SLOW		33		/* 802.3ad slow protocol */
#define	AF_SCLUSTER	34		/* Sitara cluster protocol */
#define	AF_ARP		35
#define	AF_BLUETOOTH	36		/* Bluetooth sockets */
#define	AF_MAX		37
```

#### The one used for IP is AF_INET. It is a symbol for the constant 2. 

#### It is the address family listed in the `sa_family` field of socketaddr that decides how exactly the vaguely named bytes of sa_data wil be used. 

#### Specifically, whenever the address family is AF_INET, we can use `struct sockaddr_in` found in netinet/in.h, where `sockaddr` is expected:

```
/*
 * Socket address, internet style.
 */
struct sockaddr_in {
	uint8_t		sin_len;
	sa_family_t	sin_family;
	in_port_t	sin_port;
	struct	in_addr sin_addr;
	char	sin_zero[8];
};
```

We can visaulize its organization this way:

#### The three important fields are sin_family, which is byte 1 of the structure, sin_port, a 16-bit value found in bytes 2 and 3, and sin_Addr, a 32-bit integer representation of the IP address, stored in bytes 4-7.

#### Now, let us try to fill it out. Let us assume we are trying to write a client for the daytime protocol, which siply states that its server will write a text string representing the current date and time to port 13. We want to use TCP/IP, so we need to specify AF_INET in the address family field. AF_INET is deinfed as 2. Let us use the IP address of 192.43.244.18, which is the time server of US federal government. 

#### By the way the `sin_addr` field is declared as being of the `struct in_addr` type, which is defined in netient/in.h:

```
/*
 * Internet address (a structure for historical reasons)
 */
struct in_addr {
	in_addr_t s_addr;
};
```







