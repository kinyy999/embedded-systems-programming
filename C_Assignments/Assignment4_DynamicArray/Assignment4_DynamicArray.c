#include <stdlib.h>
#include "Assignment4_DynamicArrayHeader.h"

DynamicArray *DynamicArrayCreate(int size, int blockSize)
{
    DynamicArray *da = 0;

    if ((size <= 0) || (blockSize <= 0))
    {
        return 0;
    }

    da = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (da == 0)
    {
        return 0;
    }

    da->dArray = (int *)malloc((size_t)size * sizeof(int));
    if (da->dArray == 0)
    {
        free(da);
        return 0;
    }

    da->dArraySize = size;
    da->dArrayBlockSize = blockSize;
    da->NumOfElements = 0;

    return da;
}

void DynamicArrayDestroy(DynamicArray *DynamicArrayPtr)
{
    if (DynamicArrayPtr == 0)
    {
        return;
    }

    free(DynamicArrayPtr->dArray);
    DynamicArrayPtr->dArray = 0;

    free(DynamicArrayPtr);
}

DynamicArrayError DynamicArrayInsert(DynamicArray *DynamicArrayPtr, int data)
{
    int newSize = 0;
    int *newPtr = 0;

    if (DynamicArrayPtr == 0)
    {
        return DYNAMIC_ARRAY_NULL_PTR_ERROR;
    }

    /* Need to grow? */
    if (DynamicArrayPtr->NumOfElements == DynamicArrayPtr->dArraySize)
    {
        newSize = DynamicArrayPtr->dArraySize + DynamicArrayPtr->dArrayBlockSize;

        newPtr = (int *)realloc(DynamicArrayPtr->dArray, (size_t)newSize * sizeof(int));
        if (newPtr == 0)
        {
            return DYNAMIC_ARRAY_ALLOCATION_ERROR;
        }

        DynamicArrayPtr->dArray = newPtr;
        DynamicArrayPtr->dArraySize = newSize;
    }

    DynamicArrayPtr->dArray[DynamicArrayPtr->NumOfElements] = data;
    DynamicArrayPtr->NumOfElements++;

    return DYNAMIC_ARRAY_SUCCESS;
}

DynamicArrayError DynamicArrayDelete(DynamicArray *DynamicArrayPtr, int *data)
{
    int freeSpace = 0;
    int newSize = 0;
    int *newPtr = 0;

    if (DynamicArrayPtr == 0)
    {
        return DYNAMIC_ARRAY_NULL_PTR_ERROR;
    }

    if (data == 0)
    {
        return DYNAMIC_ARRAY_DATA_PTR_ERROR;
    }

    if (DynamicArrayPtr->NumOfElements == 0)
    {
        return DYNAMIC_ARRAY_EMPTY_ERROR;
    }

    /* LIFO delete */
    DynamicArrayPtr->NumOfElements--;
    *data = DynamicArrayPtr->dArray[DynamicArrayPtr->NumOfElements];

    /* Optional shrink:
       If we have at least one full block free, shrink by one block.
       Keep at least one block as minimal capacity.
    */
    freeSpace = DynamicArrayPtr->dArraySize - DynamicArrayPtr->NumOfElements;
    if (freeSpace >= DynamicArrayPtr->dArrayBlockSize)
    {
        newSize = DynamicArrayPtr->dArraySize - DynamicArrayPtr->dArrayBlockSize;

        if (newSize < DynamicArrayPtr->dArrayBlockSize)
        {
            newSize = DynamicArrayPtr->dArrayBlockSize;
        }

        if (newSize != DynamicArrayPtr->dArraySize)
        {
            newPtr = (int *)realloc(DynamicArrayPtr->dArray, (size_t)newSize * sizeof(int));
            if (newPtr == 0)
            {
                /* Shrink failed (array still valid with old buffer) */
                return DYNAMIC_ARRAY_ALLOCATION_ERROR;
            }

            DynamicArrayPtr->dArray = newPtr;
            DynamicArrayPtr->dArraySize = newSize;
        }
    }

    return DYNAMIC_ARRAY_SUCCESS;
}
