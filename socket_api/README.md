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