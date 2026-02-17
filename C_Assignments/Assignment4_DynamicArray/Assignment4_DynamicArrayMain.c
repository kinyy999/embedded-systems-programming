#include <stdio.h>
#include "Assignment4_DynamicArrayHeader.h"

static void PrintStatus(const DynamicArray *da)
{
    if (da == 0)
    {
        printf("DynamicArray: NULL\n");
        return;
    }

    printf("DynamicArray status: size=%d, block=%d, elements=%d\n",
           da->dArraySize, da->dArrayBlockSize, da->NumOfElements);
}

static void PrintError(DynamicArrayError err)
{
    switch (err)
    {
        case DYNAMIC_ARRAY_SUCCESS:             printf("SUCCESS\n"); break;
        case DYNAMIC_ARRAY_NULL_PTR_ERROR:      printf("NULL_PTR_ERROR\n"); break;
        case DYNAMIC_ARRAY_ALLOCATION_ERROR:    printf("ALLOCATION_ERROR\n"); break;
        case DYNAMIC_ARRAY_SIZE_ERROR:          printf("SIZE_ERROR\n"); break;
        case DYNAMIC_ARRAY_EMPTY_ERROR:         printf("EMPTY_ERROR\n"); break;
        case DYNAMIC_ARRAY_DATA_PTR_ERROR:      printf("DATA_PTR_ERROR\n"); break;
        default:                                printf("UNKNOWN_ERROR\n"); break;
    }
}

int main(void)
{
    DynamicArray *da = 0;
    DynamicArrayError err;
    int out = 0;
    int i = 0;

    printf("Create DynamicArray(size=3, block=2)\n");
    da = DynamicArrayCreate(3, 2);
    if (da == 0)
    {
        printf("Create failed (NULL)\n");
        return 0;
    }
    PrintStatus(da);
    printf("\n");

    printf("Insert 6 values (forces resize)\n");
    for (i = 0; i < 6; ++i)
    {
        err = DynamicArrayInsert(da, (i + 1) * 10);
        PrintError(err);
        PrintStatus(da);
    }
    printf("\n");

    printf("Delete 7 times (1 more than elements to test EMPTY)\n");
    for (i = 0; i < 7; ++i)
    {
        err = DynamicArrayDelete(da, &out);
        if (err == DYNAMIC_ARRAY_SUCCESS)
        {
            printf("Deleted value: %d\n", out);
        }
        else
        {
            PrintError(err);
        }
        PrintStatus(da);
    }
    printf("\n");

    printf("Destroy\n");
    DynamicArrayDestroy(da);
    da = 0;

    return 0;
}
