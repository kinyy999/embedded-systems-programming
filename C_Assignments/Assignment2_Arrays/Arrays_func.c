
#include <stdio.h>
#include "Arrays_Headers.h"
#define MAX_SIZE 100
#define MIN_SIZE 0
#define MAX_ASCII_CHAR  '~'
#define MIN_ASCII_CHAR '!'


int ArrayAverage(int arr[], int size)
{
    int sum = 0;

    if (arr == NULL)
        return NULL_ARRAY_ERROR;

    if (size <= 0)
        return SIZE_ERROR;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum / size; /* integer average */
}

int Most_Appearance(int arr[], int arrSize)
{
    int maxCount = 0;
    int mostFrq = arr[0];
    for (int i = 0; i < arrSize; i++)
    {
        int count = 0;
        for (int j = 0; j < arrSize; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }
        
        if(count > maxCount)
        {
            mostFrq = arr[i];
            maxCount = count;
        }


    }
    return mostFrq;
}

int ArrangeEvenOdd(int arr[], int size)
{
    int i = 0;
    int even_count = 0;

    if (arr == 0)
    {
        return NULL_ARRAY_ERROR;
    }

    if (size <= 0)
    {
        return SIZE_ERROR;
    }

    /* Pass 1: count evens */
    for (i = 0; i < size; ++i)
    {
        if ((arr[i] % 2) == 0)
        {
            ++even_count;
        }
    }

    /* Already arranged cases */
    if ((even_count == 0) || (even_count == size))
    {
        return even_count;
    }

    /* Pass 2: stable write into temp using two indices */
    {
        int temp[size];
        int even_write = 0;
        int odd_write  = even_count;  /* odds start after evens */

        for (i = 0; i < size; ++i)
        {
            if ((arr[i] % 2) == 0)
            {
                temp[even_write] = arr[i];
                ++even_write;
            }
            else
            {
                temp[odd_write] = arr[i];
                ++odd_write;
            }
        }

        /* Copy back */
        for (i = 0; i < size; ++i)
        {
            arr[i] = temp[i];
        }
    }

    return even_count;
}

static void SwapInts(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int SortArrayAscending(int arr[], int size)
{
    int i = 0;
    int j = 0;

    if (arr == 0)
    {
        return NULL_ARRAY_ERROR;
    }

    if (size <= 0)
    {
        return SIZE_ERROR;
    }

    for (i = 0; i < size - 1; ++i)
    {
        for (j = 0; j < size - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                SwapInts(&arr[j], &arr[j + 1]);
            }
        }
    }

    return 0;
}


int SortBinaryArray(int arr[], int size)
{
    int i = 0;
    int zero_count = 0;

    if (arr == 0)
    {
        return NULL_ARRAY_ERROR;
    }

    if (size <= 0)
    {
        return SIZE_ERROR;
    }

    /* Count number of zeros */
    for (i = 0; i < size; ++i)
    {
        if (arr[i] == 0)
        {
            ++zero_count;
        }
    }

    /* Fill zeros first */
    for (i = 0; i < zero_count; ++i)
    {
        arr[i] = 0;
    }

    /* Fill ones after */
    for (i = zero_count; i < size; ++i)
    {
        arr[i] = 1;
    }

    return 0;
}