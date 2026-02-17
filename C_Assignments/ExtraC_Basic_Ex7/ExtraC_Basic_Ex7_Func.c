#include "ExtraC_Basic_Ex7_Header.h"



int Factorial(int n)
{
    int result = 1;

    if (n < 0)
        return FACTORIAL_ERROR;

    while (n > 1)
    {
        result *= n;
        n--;
    }

    return result;
}


int IsPalindrome(int n)
{
    int original = n;
    int reversed = 0;

    if (n < 0)
        n = n *-1;

    while (n > 0)
    {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }

    return (original == reversed);
}


int IsAscendingDigits(int n)
{
    int prevDigit;
    int currDigit;

    if (n < 0)
        n *= -1;

    prevDigit = n % 10;
    n /= 10;

    while (n > 0)
    {
        currDigit = n % 10;

        if (currDigit > prevDigit)
            return 0;

        prevDigit = currDigit;
        n /= 10;
    }

    return 1;
}


int IsPrime(int n)
{
    int i;

    if (n <= 1)
        return 0;

    if (n == 2)
        return 1;

    if (n % 2 == 0)
        return 0;

    for (i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int ReverseNumber(int n)
{
    int reversed = 0;
    int sign = 1;

    if (n < 0)
    {
        sign = -1;
        n *= -1;
    }

    while (n > 0)
    {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }

    return reversed * sign;
}


int CheckDigitsMatch(int base, int check)
{
    int baseDigits[10] = {0};
    int checkDigits[10] = {0};
    int baseArr[10];
    int checkArr[10];
    int len = 0;
    int samePlace = 0;
    int diffPlace = 0;
    int i, j;

    if (base <= 0 || check <= 0)
        return -1;

    /* extract digits */
    while (base > 0 && check > 0)
    {
        baseArr[len] = base % 10;
        checkArr[len] = check % 10;

        if (baseDigits[baseArr[len]] || checkDigits[checkArr[len]])
            return -1;

        baseDigits[baseArr[len]] = 1;
        checkDigits[checkArr[len]] = 1;

        base /= 10;
        check /= 10;
        len++;
    }

    if (base > 0 || check > 0)
        return -1;

    /* same place */
    for (i = 0; i < len; i++)
    {
        if (baseArr[i] == checkArr[i])
            samePlace++;
    }

    /* different place */
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (i != j && baseArr[i] == checkArr[j])
                diffPlace++;
        }
    }

    return (samePlace * 10) + diffPlace;
}
