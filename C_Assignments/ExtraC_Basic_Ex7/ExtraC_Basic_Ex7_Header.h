#ifndef ARRAYS_HEADERS_H
#define ARRAYS_HEADERS_H
#include <stddef.h>
#include <stdio.h>
/*
   Return codes / Errors
*/
#define OK                 1

#define NULL_ARRAY_ERROR  -1
#define SIZE_ERROR        -2
#define FACTORIAL_ERROR   -3



/*
Description -
Calculates the factorial of a given integer number.

Input -
n : Integer number received from keyboard.

Output -
Returns the factorial value of n.

Error -
FACTORIAL_ERROR : n is negative.
*/
int Factorial(int n);



/*
Description -
Checks whether an integer number is a palindrome.

Input -
n : Integer number.

Output -
Returns 1 if the number is palindrome, otherwise 0.
*/
int IsPalindrome(int n);


/*
Description -
Checks whether all digits of an integer number are in ascending order.

Input -
n : Integer number.

Output -
Returns 1 if digits are in ascending order, otherwise 0.
*/
int IsAscendingDigits(int n);


/*
Description -
Checks whether a positive integer number is a prime number.

Input -
n : Positive integer number.

Output -
Returns 1 if the number is prime, otherwise 0.
*/
int IsPrime(int n);


/*
Description -
Reverses the digits of a given integer number.

Input -
n : Integer number.

Output -
Returns the reversed number.
*/
int ReverseNumber(int n);


/*
Description -
Checks how many digits of the check number appear in the base number
in the same place and how many appear in different places.

Input -
base  : Positive integer base number (with unique digits).
check : Positive integer check number (with unique digits).

Output -
Returns a two-digit integer:
tens  - count of digits in the same place
ones  - count of digits in different places

Error -
Returns -1 in case of invalid input.
*/
int CheckDigitsMatch(int base, int check);


#endif /* ARRAYS_HEADERS_H */
