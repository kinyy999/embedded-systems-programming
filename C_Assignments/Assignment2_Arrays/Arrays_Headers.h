
#ifndef ARRAY_2_ASSIGNMENT_HEADER_H
#define ARRAY_2_ASSIGNMENT_HEADER_H

#define OK 0
#define NULL_ARRAY_ERROR    -1
#define SIZE_ERROR          -2


/* 
Function Prototypes


Description -
Calculates the average value of elements in an integer array
using integer division.

Input -
arr  : Array of integers.
size : Number of elements in the array.

Output -
Returns the integer average of the array elements.

Error -
NULL_ARRAY_ERROR : arr is NULL.
SIZE_ERROR       : size is less than or equal to 0.
*/
int ArrayAverage(int arr[], int size);


/*
discription - *
Input -
Output - OK or ERROR
Error - SIZE_ERROR or CHAR_TO_PRINT_ERROR              
*/
int Most_Appearance(int arr[], int arrSize);


/*
Description -
Rearranges an integer array so that all even numbers appear
first, followed by all odd numbers.
The relative order of even numbers and odd numbers is preserved.

Input -
arr  : Array of integers (negative values are allowed).
size : Number of elements in the array.

Output -
Returns the number of even elements in the array.

Error -
NULL_ARRAY_ERROR : arr is NULL.
SIZE_ERROR       : size is less than or equal to 0.
*/

int ArrangeEvenOdd(int arr[], int size);


/*
Description -
Sorts an integer array in ascending order (in-place).

Input -
arr  : Array of integers (negative values are allowed).
size : Number of elements in the array.

Output -
Returns SUCCESS if sorting was performed successfully.

Error -
NULL_ARRAY_ERROR : arr is NULL.
SIZE_ERROR       : size is less than or equal to 0.
*/
int SortArrayAscending(int arr[], int size);


/*
Description -
Sorts an array containing only 0 and 1 values so that all
0's appear first, followed by all 1's.

Input -
arr  : Array of integers (allowed values are only 0 or 1).
size : Number of elements in the array.

Output -
Returns 0 if sorting was performed successfully.

Error -
NULL_ARRAY_ERROR : arr is NULL.
SIZE_ERROR       : size is less than or equal to 0.
*/
int SortBinaryArray(int arr[], int size);
#endif