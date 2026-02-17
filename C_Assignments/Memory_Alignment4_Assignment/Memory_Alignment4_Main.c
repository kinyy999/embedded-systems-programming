#include <stdio.h>

typedef struct structb_tag
{
    short int s;
    int c;
    int* i;
} structb_t;

typedef struct structc_tag
{
    char c;
    double d;
    int s;
} structc_t;

typedef struct structd_tag
{
    double d;
    int s;
    char c;
} structd_t;

#pragma pack(push, 1)
typedef struct
{
    char m_ch1;
    int* m_ptr;
    char m_ch2;
} CheckPragma;
#pragma pack(pop)



unsigned int CountBits_UChar(unsigned char num)
{
    unsigned int count = 0;

    while (num != 0)
    {
        count += (num & 1);
        num >>= 1;
    }

    return count;
}

unsigned int CountBits_UInt(unsigned int num)
{
    unsigned int count = 0;

    while (num != 0)
    {
        count += (num & 1);
        num >>= 1;
    }

    return count;
}

unsigned char ReverseBits_UChar(unsigned char num)
{
    unsigned char result = 0;
    int i;

    for (i = 0; i < 8; i++)
    {
        result <<= 1;       
        result |= (num & 1);
        num >>= 1;          
    }

    return result;
}

unsigned int ReverseBits_UInt(unsigned int num)
{
    unsigned int result = 0;
    int i;

    for (i = 0; i < 8*sizeof(int); i++)
    {
        result <<= 1;      
        result |= (num & 1);
        num >>= 1;           
    }

    return result;
}


int main(void)
{
    printf("sizeof(structb_t)   = %zu bytes\n", sizeof(structb_t));
    printf("sizeof(structc_t)   = %zu bytes\n", sizeof(structc_t));
    printf("sizeof(structd_t)   = %zu bytes\n", sizeof(structd_t));

    /* ללא alignment – packed */
    printf("sizeof(CheckPragma) = %zu bytes\n", sizeof(CheckPragma));


    unsigned char uc_val = 13;   /* 00001101 -> 3 ביטים דלוקים */
    unsigned int  ui_val = 29;   /* 00011101 -> 4 ביטים דלוקים */

    printf("Count bits in unsigned char (%u) = %u\n",
           uc_val, CountBits_UChar(uc_val));

    printf("Count bits in unsigned int (%u)  = %u\n",
           ui_val, CountBits_UInt(ui_val));


        unsigned char uc = 13;        /* 00001101 -> 10110000 = 176 */
    unsigned int  ui = 5;         /* 000...0101 -> 1010...0000 */

    printf("Reverse unsigned char: %u -> %u\n", uc, ReverseBits_UChar(uc));
    printf("Reverse unsigned int : %u -> %u\n", ui, ReverseBits_UInt(ui));


    return 0;
}
