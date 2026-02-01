#include <stdio.h>
#include "Assignment5_BitsHeader.h"


void PrintBinaryUC(unsigned char x)
{
    int i = 0;

    for (i = 7; i >= 0; --i)
    {
        printf("%d", (x >> i) & 1);
    }
}


void InvertBitsUC(unsigned char x, unsigned char *y)
{
    if (y == 0)
    {
        return;
    }

    *y = (unsigned char)(~x);
}


unsigned char RotateRightUC(unsigned char x, unsigned int n)
{
    n = n % 8;

    return (unsigned char)((x >> n) | (x << (8 - n)));
}

unsigned char SetBitsUC(unsigned char x, unsigned int p, unsigned int n, unsigned char y)
{
    unsigned int shift = p - n;
    unsigned char lowMask = (unsigned char)((1u << n) - 1u);
    unsigned char fieldMask = (unsigned char)(lowMask << shift);

    x = (unsigned char)(x & (unsigned char)(~fieldMask));
    x = (unsigned char)(x | (unsigned char)((y & lowMask) << shift));

    return x;
}


static int LetterToNibble(char c, unsigned char *out)
{
    if (out == 0)
    {
        return -2;
    }

    if ((c < 'a') || (c > 'o'))
    {
        return -2;
    }

    *out = (unsigned char)(c - 'a');
    return 0;
}

int Compress4Bits_NoBitfield(char *str)
{
    int len = 0;
    int read_i = 0;
    int write_i = 0;
    unsigned char a = 0;
    unsigned char b = 0;
    unsigned char packed = 0;

    if (str == 0)
    {
        return -1;
    }

    while (str[len] != '\0')
    {
        ++len;
    }

    read_i = 0;
    while (read_i < len)
    {
        if (LetterToNibble(str[read_i], &a) != 0)
        {
            return -2;
        }

        if ((read_i + 1) < len)
        {
            if (LetterToNibble(str[read_i + 1], &b) != 0)
            {
                return -2;
            }
        }
        else
        {
            b = 0x0F; /* padding */
        }

        packed = (unsigned char)((a << 4) | (b & 0x0F));
        str[write_i] = (char)packed;

        ++write_i;
        read_i += 2;
    }

    /* Not a real "string" anymore, but we keep a terminator for safe printing/debug */
    str[write_i] = '\0';

    return write_i;
}

/* bit-field packing */
typedef struct Nibbles
{
    unsigned int low  : 4;
    unsigned int high : 4;
} Nibbles;

typedef union PackByte
{
    unsigned char byte;
    Nibbles n;
} PackByte;

int Compress4Bits_Bitfield(char *str)
{
    int len = 0;
    int read_i = 0;
    int write_i = 0;
    unsigned char a = 0;
    unsigned char b = 0;
    PackByte pb;

    if (str == 0)
    {
        return -1;
    }

    while (str[len] != '\0')
    {
        ++len;
    }

    read_i = 0;
    while (read_i < len)
    {
        if (LetterToNibble(str[read_i], &a) != 0)
        {
            return -2;
        }

        if ((read_i + 1) < len)
        {
            if (LetterToNibble(str[read_i + 1], &b) != 0)
            {
                return -2;
            }
        }
        else
        {
            b = 0x0F; /* padding */
        }

        /* Assumes: low nibble = first bit-field, high nibble = second bit-field */
        pb.n.high = a;
        pb.n.low  = b;

        str[write_i] = (char)pb.byte;

        ++write_i;
        read_i += 2;
    }

    str[write_i] = '\0';
    return write_i;
}



