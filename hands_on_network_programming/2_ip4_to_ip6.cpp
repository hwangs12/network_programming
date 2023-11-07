/* IPv4 in IPv6 are expressed as follows */

/* in IPv4, 2^32 bits can be used */

/* so in IPv6, first 5 segments are zeros, next one is all ffff */

/* then the last two segments can be used to express IPv4 */

/* In full notation, this will be  */

/* 0000:0000:0000:0000:0000:ffff:xxxx:xxxx */

/* where xxxx are IPv4 */

/* in short, this is */

/* ::ffff:0:0/96 using CIDR notation */

/* last two are not expressed as :: because in IPv6 rule is that there should be only one double colons */