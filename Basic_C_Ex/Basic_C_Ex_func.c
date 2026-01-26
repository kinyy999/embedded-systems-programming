#include <stdio.h>
#include "Basic_C_Ex_Headers.h"

#define MIN_SIZE         1
#define MAX_SIZE         50

#define MIN_ASCII_CHAR   33
#define MAX_ASCII_CHAR   126

int Check_Parameters(int length, char ch2print)
{
    if (length < MIN_SIZE || length > MAX_SIZE)
    {
        return SIZE_ERROR;
    }
    if (ch2print < MIN_ASCII_CHAR || ch2print > MAX_ASCII_CHAR)
    {
        return CHAR_TO_PRINT_ERROR;
    }
    return OK;
}

int Print_line(int length, char ch2print)
{
        int result = Check_Parameters(length, ch2print);
    if (result != OK)
    {
        return result;
    }

    for (int j = 0; j < length; j++)
    {
        printf("%c", ch2print);
    }
    printf("\n");
    return OK;
}


int Print_LeftBottom_Aligend_Triag(int length, char ch2print)
{
    int result = Check_Parameters(length, ch2print);
    if (result != OK)
    {
        return result;
    }

    for (int i = 1; i <= length; i++)
    {
        Print_line(i, ch2print);
    }

    return OK;
}


int Print_LeftTop_Aligend_Triag(int length, char ch2print)
{
    int result = Check_Parameters(length, ch2print);
    if (result != OK)
    {
        return result;
    }

    for (int i = length; i >= 1; i--)
    {
        Print_line(i, ch2print);
    }

    return OK;
}


int Print_RightSide_Diamond(int length, char ch2print)
{
    int result = Check_Parameters(length, ch2print);
    if (result != OK)
    {
        return result;
    }

    for (int i = 1; i <= length; i++)
    {
        Print_line(i, ch2print);
    }

    for (int i = length - 1; i >= 1; i--)
    {
        Print_line(i, ch2print);
    }

    return OK;
}


int Print_Pyramid(int length, char ch2print)
{
    int result = Check_Parameters(length, ch2print);
    if (result != OK)
    {
        return result;
    }

    for (int i = 1; i <= length; i++)
    {
        for (int s = 0; s < length - i; s++)
        {
            printf(" ");
        }

        for (int j = 1; j <= i; j++)
        {
            printf("%c", ch2print);
            if (j < i)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return OK;
}




int Print_UpSideDown_Pyramid(int baseWidth, int length, char ch2print)
{
    int result = Check_Parameters(baseWidth, ch2print);
    if (result != OK)
    {
        return result;
    }

    if (length < 1 || length > baseWidth)
    {
        return SIZE_ERROR;
    }

    for (int i = length; i >= 1; i--)
    {
        for (int s = 0; s < baseWidth - i; s++)
        {
            printf(" ");
        }

        for (int j = 1; j <= i; j++)
        {
            printf("%c", ch2print);
            if (j < i)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return OK;
}




int Print_Diamond(int length, char ch2print)
{
    int result = Check_Parameters(length, ch2print);
    if (result != OK)
    {
        return result;
    }

    result = Print_Pyramid(length, ch2print);
    if (result != OK)
    {
        return result;
    }

    result = Print_UpSideDown_Pyramid(length, length - 1, ch2print);
    if (result != OK)
    {
        return result;
    }

    return OK;
}


