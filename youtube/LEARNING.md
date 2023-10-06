Little and big endian are two ways of storing multibyte data-types. In little endian machines, last byte of binary representation of the multibyte data-type is stored first. 
Big endian, is the other way around. 
Suppose integer is stored as 4 bytes then a variable x with value 0x01234567 

Big endian, 1, 2, 3, 4, 67, 45, 23, 01
Lit endian, 1, 2, 3, 4, 01, 23, 45, 67
