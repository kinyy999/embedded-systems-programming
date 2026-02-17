#ifndef _BITWISE_HEADER_H
#define _BITWISE_HEADER_H

#include <stdio.h>

#define BYTE_VALUES 256


/*
Description -
Builds a Look-Up Table (LUT) that stores the number of ON bits
(popcount) for every possible byte value (0-255).

Input -
None.

Output -
Fills an internal LUT array used for fast bit counting.

Error -
None.
*/
void BuildBitCountLUT();


/*
Description -
Checks whether the majority of bits in an unsigned integer are ON.

Input -
n : Unsigned integer value.

Output -
Returns 1 if more than half of the bits in n are ON.
Returns 0 otherwise.

Error -
None.
*/
unsigned int Majority(unsigned int n);


/*
Description -
Builds a Look-Up Table (LUT) that stores the mirrored (reversed)
bit pattern for every possible byte value (0-255).

Input -
None.

Output -
Fills an internal LUT array used for fast bit mirroring.

Error -
None.
*/
void BuildMirrorLUT(void);


/*
Description -
Reverses all bits in an unsigned integer using a mirror LUT.

Input -
n : Unsigned integer value.

Output -
Returns the bit-mirrored version of n.

Error -
None.
*/
unsigned int BitMirror(unsigned int n);


/*
Description -
Builds Look-Up Tables used to find positions of ON bits inside bytes.
Includes:
1. Popcount LUT (number of ON bits in each byte).
2. kth-position LUT (location of k-th ON bit in each byte).

Input -
None.

Output -
Fills internal LUT arrays for fast bit position queries.

Error -
None.
*/
void BuildThirdBitLUTs(void);


/*
Description -
Finds the index of the third ON bit in an unsigned integer
(counting from the least significant bit, starting at index 0).

Input -
n : Unsigned integer value.

Output -
Returns the index of the third ON bit.
Returns -1 if fewer than three bits are ON.

Error -
None.
*/
int IndexOfThirdSetBit_LUT(unsigned int n);


/*
Description -
Prints the binary representation of an unsigned integer.

Input -
n : Unsigned integer value.

Output -
Prints bits of n from most significant to least significant.

Error -
None.
*/
void printBits(unsigned int n);


#endif
