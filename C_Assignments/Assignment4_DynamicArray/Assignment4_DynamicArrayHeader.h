#ifndef ASSIGNMENT4_DYNAMIC_ARRAY_HEADER_H
#define ASSIGNMENT4_DYNAMIC_ARRAY_HEADER_H

/*
Description -
Dynamic array (resizable array) implementation using a struct.
Supports create/destroy/insert/delete (LIFO delete).

Struct -
DynamicArray:
dArray          : Pointer to the dynamic array buffer.
dArraySize      : Current capacity (number of allocated int elements).
dArrayBlockSize : Growth/shrink step size.
NumOfElements   : Current number of elements stored.
*/

typedef struct DynamicArray
{
    int *dArray;
    int dArraySize;
    int dArrayBlockSize;
    int NumOfElements;
} DynamicArray;

/*
Description -
All possible errors for DynamicArray functions.
*/
typedef enum DynamicArrayError
{
    DYNAMIC_ARRAY_SUCCESS = 0,
    DYNAMIC_ARRAY_NULL_PTR_ERROR,
    DYNAMIC_ARRAY_ALLOCATION_ERROR,
    DYNAMIC_ARRAY_SIZE_ERROR,
    DYNAMIC_ARRAY_EMPTY_ERROR,
    DYNAMIC_ARRAY_DATA_PTR_ERROR
} DynamicArrayError;


/*
Description -
Creates a DynamicArray object with initial capacity 'size' and growth block 'blockSize'.

Input -
size      : Initial capacity (number of ints to allocate). Must be > 0.
blockSize : Block size for resizing. Must be > 0.

Output -
Returns pointer to allocated DynamicArray on success, NULL on failure.

Error -
Returns NULL if allocation fails or if parameters are invalid.
*/
DynamicArray *DynamicArrayCreate(int size, int blockSize);


/*
Description -
Destroys the DynamicArray object and frees all allocated memory.

Input -
DynamicArrayPtr : Pointer to DynamicArray to destroy.

Output -
None.

Error -
If DynamicArrayPtr is NULL, function does nothing.
*/
void DynamicArrayDestroy(DynamicArray *DynamicArrayPtr);


/*
Description -
Inserts an integer into the DynamicArray.
If the array is full, it grows by dArrayBlockSize.

Input -
DynamicArrayPtr : Pointer to DynamicArray.
data            : Value to insert.

Output -
Returns DYNAMIC_ARRAY_SUCCESS on success.

Error -
DYNAMIC_ARRAY_NULL_PTR_ERROR      : DynamicArrayPtr is NULL.
DYNAMIC_ARRAY_ALLOCATION_ERROR    : realloc failed while growing.
*/
DynamicArrayError DynamicArrayInsert(DynamicArray *DynamicArrayPtr, int data);


/*
Description -
Deletes (removes) one integer from the DynamicArray (LIFO: removes last inserted element).
Optionally shrinks capacity by dArrayBlockSize when there is enough free space.

Input -
DynamicArrayPtr : Pointer to DynamicArray.
data            : Output pointer to receive deleted value.

Output -
Returns DYNAMIC_ARRAY_SUCCESS on success and writes deleted value into *data.

Error -
DYNAMIC_ARRAY_NULL_PTR_ERROR   : DynamicArrayPtr is NULL.
DYNAMIC_ARRAY_DATA_PTR_ERROR   : data is NULL.
DYNAMIC_ARRAY_EMPTY_ERROR      : array is empty (NumOfElements == 0).
DYNAMIC_ARRAY_ALLOCATION_ERROR : realloc failed while shrinking (optional shrink step).
*/
DynamicArrayError DynamicArrayDelete(DynamicArray *DynamicArrayPtr, int *data);

#endif /* ASSIGNMENT4_DYNAMIC_ARRAY_HEADER_H */
