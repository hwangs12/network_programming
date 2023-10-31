/* HOW TO READ PARTIALLY FIXED ADDRESS */

/* EX) 172.16.0.0/12 */
/* EX) 192.168.1.192/28 */

/* A: They are number of bits free to use from 32 bits from right to left */

/* For 172.16.0.0/12, you are free to use 20 bits from 172.16.0.0 */

/* What that means is you can use 172.16.0.0 to 172.16.0.255 for the first 8 bits, with next 8 bits for the second right 172.16.0-255.0-255 then 20-16 = 4 remaining bits from 172.16-32.0-255.0-255 on the third right, comprising of 20 bits in total. Basically free to use 2 to the power of 20 from 172.16.0.0 and you count from rightmost number to be the lowest. */
