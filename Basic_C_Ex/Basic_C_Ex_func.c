#include <stdio.h>
#include "Basic_C_Ex_Headers.h"

#define MIN_SIZE         1
#define MAX_SIZE         50

#define MIN_ASCII_CHAR   33
#define MAX_ASCII_CHAR   126

int Check_Parameters(int lines, char ch2print)
{
    if (lines < MIN_SIZE || lines > MAX_SIZE)
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
    for (int j = 0; j < length; j++)
    {
        printf("%c", ch2print);
    }
    printf("\n");
    return OK;
}


int Print_LeftBottom_Aligend_Triag(int lines, char ch2print)
{
    int result = Check_Parameters(lines, ch2print);
    if (result != OK)
    {
        return result;
    }

    for (int i = 1; i <= lines; i++)
    {
        Print_line(i, ch2print);
    }

    return OK;
}


int Print_LeftTop_Aligend_Triag(int lines, char ch2print)
{
    int result = Check_Parameters(lines, ch2print);
    if (result != OK)
    {
        return result;
    }

    for (int i = lines; i >= 1; i--)
    {
        Print_line(i, ch2print);
    }

    return OK;
}


int Print_RightSide_Diamond(int lines, char ch2print)
{
    int result = Check_Parameters(lines, ch2print);
    if (result != OK)
    {
        return result;
    }

    for (int i = 1; i <= lines; i++)
    {
        Print_line(i, ch2print);
    }

    for (int i = lines - 1; i >= 1; i--)
    {
        Print_line(i, ch2print);
    }

    return OK;
}


int Print_Pyramid(int lines, char ch2print)
{
    int result = Check_Parameters(lines, ch2print);
    if (result != OK)
    {
        return result;
    }

    for (int i = 1; i <= lines; i++)
    {
        for (int s = 0; s < lines - i; s++)
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




int Print_UpSideDown_Pyramid(int lines, char ch2print)
{
    int result = Check_Parameters(lines, ch2print);
    if (result != OK)
    {
        return result;
    }

    for (int i = lines; i >= 1; i--)
    {
        for (int s = 0; s < lines - i; s++)
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



int Print_Diamond(int lines, char ch2print)
{
    int result = Check_Parameters(lines, ch2print);
    if (result != OK)
    {
        return result;
    }

    Print_Pyramid(lines, ch2print);
    Print_UpSideDown_Pyramid(lines - 1, ch2print);

    return OK;
}


