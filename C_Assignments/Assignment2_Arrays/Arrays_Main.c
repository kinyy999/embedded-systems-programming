
#include <stdio.h>
#include "Arrays_Headers.h"

static void PrintArray(const int arr[], int size)
{
    int i = 0;

    if (arr == 0)
    {
        printf("NULL\n");
        return;
    }

    printf("[");
    for (i = 0; i < size; ++i)
    {
        printf("%d", arr[i]);
        if (i < (size - 1))
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{
    int arr_avg[] = {10, 20, 30, 40, 50};

    /*  Valid array
        NULL array 
        Negative size 
    */
    printf("Valid array result: %d\n", ArrayAverage(arr_avg, 5));
    printf("NULL array result: %d\n", ArrayAverage(NULL, 5));
    printf("Negative size result: %d\n", ArrayAverage(arr_avg, -3));



    int arr2[5] = {2, 2, 3, 4, 3};

    int resultQ2 = Most_Appearance(arr2, 5);
    printf("Most frequent value: %d\n", resultQ2);



    /* ===== Test 1: Valid array ===== */
    {
        int arr[] = { 3, -4, 7, 2, -9, 0, 8, -1, 6, 5 };
        int size = (int)(sizeof(arr) / sizeof(arr[0]));
        int result = 0;

        printf("Test 1: Valid array\n");
        printf("Before: ");
        PrintArray(arr, size);

        result = ArrangeEvenOdd(arr, size);

        if (result >= 0)
        {
            printf("After : ");
            PrintArray(arr, size);
            printf("Even count = %d\n", result);
        }

        printf("\n");
    }

    /* ===== Test 2: NULL array ===== */
    {
        int *arr = 0;
        int size = 5;
        int result = 0;

        printf("Test 2: NULL array\n");
        result = ArrangeEvenOdd(arr, size);

        if (result == NULL_ARRAY_ERROR)
        {
            printf("Passed: NULL_ARRAY_ERROR\n");
        }

        printf("\n");
    }

    /* ===== Test 3: Invalid size ===== */
    {
        int arr[] = { 2, 4, 6 };
        int size = 0;
        int result = 0;

        printf("Test 3: Invalid size\n");
        result = ArrangeEvenOdd(arr, size);

        if (result == SIZE_ERROR)
        {
            printf("Passed: SIZE_ERROR\n");
        }

        printf("\n");
    }

    /* ===== Test 4: Sort array ascending ===== */
    {
        int arr[] = { 7, -3, 10, 0, -5, 2, 8, 1 };
        int size = (int)(sizeof(arr) / sizeof(arr[0]));
        int result = 0;

        printf("Test 4: Sort array ascending\n");
        printf("Before: ");
        PrintArray(arr, size);

        result = SortArrayAscending(arr, size);

        if (result == 0)
        {
            printf("After : ");
            PrintArray(arr, size);
        }
        else if (result == NULL_ARRAY_ERROR)
        {
            printf("Error: NULL_ARRAY_ERROR\n");
        }
        else if (result == SIZE_ERROR)
        {
            printf("Error: SIZE_ERROR\n");
        }

        printf("\n");
    } 
    
        /* ===== Test 5: Binary array (0s and 1s) ===== */
    {
        int arr[] = { 1, 0, 1, 1, 0, 0, 1, 0 };
        int size = (int)(sizeof(arr) / sizeof(arr[0]));
        int result = 0;

        printf("Test 5: Binary array sort (0s then 1s)\n");
        printf("Before: ");
        PrintArray(arr, size);

        result = SortBinaryArray(arr, size);

        if (result == 0)
        {
            printf("After : ");
            PrintArray(arr, size);
        }
        else if (result == NULL_ARRAY_ERROR)
        {
            printf("Error: NULL_ARRAY_ERROR\n");
        }
        else if (result == SIZE_ERROR)
        {
            printf("Error: SIZE_ERROR\n");
        }

        printf("\n");
    }


    return 0;
}
