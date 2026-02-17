#ifndef MY_STRING_UTILS_H   
#define MY_STRING_UTILS_H  


#define OK                    1
#define NOT_OK                0

#define NULL_STRING_ERROR    -1
#define NULL_BUFFER_ERROR    -2
#define NEGATIVE_N_ERROR     -3
#define INVALID_FORMAT_ERROR -4



/*
Description -
Generic parameter validation function for the string/number utilities.
Checks only the requested parameters (using flags) and returns OK or an error code.

Input -
s1   : First string pointer (can be NULL if not checked).
s2   : Second string pointer (can be NULL if not checked).
out  : Output int pointer (can be NULL if not checked).
buf  : Output buffer pointer (can be NULL if not checked).
n    : Integer parameter n (used when CHECK_N_NONNEG is set).
flags: Bitmask indicating which validations to perform.

Output -
Returns OK if all requested checks pass.

Error -
NULL_STRING_ERROR    : required string pointer is NULL.
NULL_BUFFER_ERROR    : required buffer pointer is NULL.
INVALID_FORMAT_ERROR : required output pointer is NULL.
NEGATIVE_N_ERROR     : n is negative.
*/
int CheckParameters(const char *s1, const char *s2, const int *out, const char *buf, int n, int flags);




/*
Description -
Calculates the length of a string by counting the number of characters
until the null terminator ('\0') is reached.

Input -
char str[] : Pointer to a null-terminated string.

Output -
Returns the length of the string (number of characters, excluding '\0').

Error -
NULL_STRING_ERROR : str is NULL.
*/
int MyStrlen(char str[]);




/*
Description -
Appends up to n characters from string s2 to the end of string s1.
The first character from s2 overwrites the '\0' of s1, and a new
null-terminated string is created.

Input -
s1 : Destination string (null-terminated) with enough space to store the result.
s2 : Source string (null-terminated) from which characters are copied.
n  : Maximum number of characters to append from s2.

Output -
Returns a pointer to the destination string s1.

Error -
NULL_STRING_ERROR : s1 or s2 is NULL.
NEGATIVE_N_ERROR  : n is negative.
*/
char* MyStrncat(char *s1, const char *s2, int n);




/*
Description -
Compares two null-terminated strings character by character
according to their ASCII values.

Input -
s1 : First null-terminated string to compare.
s2 : Second null-terminated string to compare.

Output -
Returns:
0  : If both strings are equal.
<0 : If s1 is lexicographically smaller than s2.
>0 : If s1 is lexicographically greater than s2.

Error -
NULL_STRING_ERROR : s1 or s2 is NULL.
*/
int MyStrcmp(const char *s1, const char *s2);



/*
Description -
Compares up to n characters of two null-terminated strings
character by character according to their ASCII values.

Input -
s1 : First null-terminated string to compare.
s2 : Second null-terminated string to compare.
n  : Maximum number of characters to compare.

Output -
Returns:
0  : If the first n characters of both strings are equal.
<0 : If s1 is lexicographically smaller than s2.
>0 : If s1 is lexicographically greater than s2.

Error -
NULL_STRING_ERROR : s1 or s2 is NULL.
NEGATIVE_N_ERROR  : n is negative.
*/
int MyStrncmp(const char *s1, const char *s2, int n);


/*
Description -
Reverses a null-terminated string in place by swapping characters
from the beginning and the end of the string until the middle is reached.

Input -
_str : Null-terminated string to be reversed.

Output -
Returns OK if the string was successfully reversed.

Error -
NULL_STRING_ERROR : _str is NULL.
*/
int ReverseStr(char *_str);


/*
Description -
Checks whether a null-terminated string is a palindrome.
A string is considered a palindrome if it reads the same
from left to right and from right to left.

Input -
_str : Null-terminated string to be checked.

Output -
Returns:
1 : If the string is a palindrome.
0 : If the string is not a palindrome.

Error -
NULL_STRING_ERROR : _str is NULL.
*/
int IsPalindrome(char *_str);




/*
Description -
Converts a null-terminated string representing an integer number
into an int value. The function handles optional leading spaces
and an optional sign ('+' or '-').

Input -
_str : Null-terminated string containing the number to convert.
_num : Pointer to an integer where the converted value will be stored.

Output -
Returns OK if the conversion was successful.

Error -
NULL_STRING_ERROR   : _str or _num is NULL.
INVALID_FORMAT_ERROR: The string does not represent a valid integer.
*/
int MyAToI(char *_str, int *_num);


/*
Description -
Converts an integer number into a null-terminated string.
The function stores the resulting string representation
of the number in the provided buffer.

Input -
_num    : Integer number to be converted.
_buffer : Pointer to a character buffer where the resulting
          null-terminated string will be stored.

Output -
Returns OK if the conversion was successful.

Error -
NULL_BUFFER_ERROR : _buffer is NULL.
*/
int MyIToA(int _num, char *_buffer);


#endif
