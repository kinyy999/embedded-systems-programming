#include <stdio.h>
#include "Assignment5_BitsHeader.h"

static void PrintCompressedBytes(const char *buf, int count)
{
    int i = 0;

    for (i = 0; i < count; ++i)
    {
        PrintBinaryUC((unsigned char)buf[i]);
        printf("\n");
    }
}


int main(void)
{
    unsigned char x = 0xEA;   /* 11101010 */
    unsigned char y = 0;

    printf("x = ");
    PrintBinaryUC(x);
    printf(" (binary)\n");

    InvertBitsUC(x, &y);

    printf("x inverted = ");
    PrintBinaryUC(y);
    printf(" (binary)\n");


    /*Rotate right test */
    {
        unsigned char x = 0xA7; /* 10100111 */
        unsigned char y = 0;
        unsigned int n = 3;

        printf("x = ");
        PrintBinaryUC(x);
        printf(" (binary)\n");

        y = RotateRightUC(x, n);

        printf("x rotated by %u = ", n);
        PrintBinaryUC(y);
        printf(" (binary)\n");
    }


        /* ===== Set bits test ===== */
    {
        unsigned char x = 0xAA; /* 10101010 */
        unsigned char y = 0xA7; /* 10100111 */
        unsigned int n = 3;
        unsigned int p = 6;
        unsigned char result = 0;

        printf("x = ");
        PrintBinaryUC(x);
        printf(" (binary)\n");

        printf("y = ");
        PrintBinaryUC(y);
        printf(" (binary)\n");

        result = SetBitsUC(x, p, n, y);

        printf("setbits n = %u, p = %u gives x = ", n, p);
        PrintBinaryUC(result);
        printf(" (binary)\n");
    }

    
    /* ===== Packing test: no bitfield ===== */
    {
        char s1[] = "abcdo"; /* odd length -> padding in last nibble */
        int compressedSize = 0;

        printf("Packing (no bitfield)\n");
        printf("Original: %s\n", s1);

        compressedSize = Compress4Bits_NoBitfield(s1);
        if (compressedSize < 0)
        {
            printf("Error: %d\n\n", compressedSize);
        }
        else
        {
            printf("Compressed bytes (binary):\n");
            PrintCompressedBytes(s1, compressedSize);
            printf("\n");
        }
    }

    /* ===== Packing test: bitfield ===== */
    {
        char s2[] = "abcdo";
        int compressedSize = 0;

        printf("Packing (bitfield)\n");
        printf("Original: %s\n", s2);

        compressedSize = Compress4Bits_Bitfield(s2);
        if (compressedSize < 0)
        {
            printf("Error: %d\n\n", compressedSize);
        }
        else
        {
            printf("Compressed bytes (binary):\n");
            PrintCompressedBytes(s2, compressedSize);
            printf("\n");
        }
    }

    return 0;
}
