#ifndef ASSIGNMENT5_BITS_HEADER_H
#define ASSIGNMENT5_BITS_HEADER_H

/*
Description -
Prints an unsigned char value in binary form (8 bits).

Input -
x : Unsigned char value to print.

Output -
Prints the value of x in binary format (MSB to LSB).

Error -
None.
*/
void PrintBinaryUC(unsigned char x);


/*
Description -
Inverts all bits of an unsigned char x and stores the result in y.

Input -
x : Unsigned char value to invert.
y : Pointer to unsigned char where the inverted value will be stored.

Output -
Stores the inverted value of x in *y.

Error -
y is NULL.
*/
void InvertBitsUC(unsigned char x, unsigned char *y);


/*
Description -
Rotates the bits of an unsigned char value to the right by n positions.
Rotation is circular, no bits are lost.

Input -
x : Unsigned char value to rotate.
n : Number of bit positions to rotate right.

Output -
Returns the rotated value of x.

Error -
None.
*/
unsigned char RotateRightUC(unsigned char x, unsigned int n);



/*
Description -
Returns x with the n bits that begin at position p replaced
by the rightmost n bits of unsigned char y.
All other bits of x remain unchanged.

Input -
x : Unsigned char value to modify.
p : Bit position (0 = LSB).
n : Number of bits to set.
y : Unsigned char value providing the rightmost n bits.

Output -
Returns the modified value of x.

Error -
None.
*/
unsigned char SetBitsUC(unsigned char x, unsigned int p, unsigned int n, unsigned char y);


/*
Description -
Compresses a string that contains only the letters:
a b c d e f g h i j k l m n o
Each letter is encoded using 4 bits (0..14).
Two letters are packed into one byte:
- First letter in the high nibble (bits 7..4)
- Second letter in the low nibble (bits 3..0)
If the string length is odd, the last low nibble is padded with 0xF.

Compression is performed in-place (inside the same char array).

Input -
str : Pointer to a null-terminated string containing only 'a'..'o'.

Output -
Returns the number of compressed bytes written into str.

Error -
Returns -1 if str is NULL.
Returns -2 if str contains a character outside 'a'..'o'.
*/
int Compress4Bits_NoBitfield(char *str);


/*
Description -
Same compression as Compress4Bits_NoBitfield, but implemented using
bit-fields with struct and union.

Note -
Bit-field layout can be compiler dependent. This function assumes GCC-like
layout where the first 4-bit field maps to the low nibble.

Input -
str : Pointer to a null-terminated string containing only 'a'..'o'.

Output -
Returns the number of compressed bytes written into str.

Error -
Returns -1 if str is NULL.
Returns -2 if str contains a character outside 'a'..'o'.
*/
int Compress4Bits_Bitfield(char *str);

#endif /* ASSIGNMENT5_BITS_HEADER_H */
