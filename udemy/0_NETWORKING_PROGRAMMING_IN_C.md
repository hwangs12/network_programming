# OSI MODEL

## - Application Layer - Ping, HTTP, WhatsApp, mobile apps
## - Transport Layer - Application to Application - ex) UDP, TCP
## - Network Layer - Source to Destination machine - IP, IPv6
## - Data link layer - concerned with node to node delivery (L2 Routing) - Ethernet

## DATA ENCAPSULATION AND DECAPSULATION

### DATA ENCAPSULATION 
#### - happens by sending machine
#### - application generates a message
#### - in transport layer, Attach TP hdr (Encode the information of sending and receiving process)
#### - in network layer, IP encoded source and destination addressess
#### - in physical layer, attach mac header, encode current and next node MAC address

### DATA DECAPSULATION
#### it's same as encapsulation but you decode from physical to application level. 