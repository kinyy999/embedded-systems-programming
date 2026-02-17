
#include "Bitwise.h"





static unsigned char bitCountLUT[BYTE_VALUES];
static unsigned char mirrorLUT[BYTE_VALUES];



void BuildBitCountLUT()
{
    for (int i = 0; i < BYTE_VALUES; i++)
    {
        int count = 0;
        int val = i;

        while (val)
        {
            count += (val & 1);
            val >>= 1;
        }

        bitCountLUT[i] = count;
    }
}

unsigned int Majority(unsigned int n)
{
    int bitcount = 0;
    int totalBits = sizeof(unsigned int) * 8;

    while (n>0)
    {
        bitcount += bitCountLUT[n & 0xFF];  
        n >>= 8;                       
    }

    return (bitcount > totalBits / 2);
}

void BuildMirrorLUT(void)
{
    for (int i = 0; i < BYTE_VALUES; i++)
    {
        unsigned char temp = (unsigned char)i;
        unsigned char mirror = 0;

        for (int j = 0; j < 8; j++)
        {
            mirror <<= 1;             
            mirror |= (temp & 1u);     
            temp >>= 1;               
        }

        mirrorLUT[i] = mirror;
    }
}


unsigned int BitMirror(unsigned int n)
{
    unsigned int result = 0;
    unsigned int bytes = (unsigned int)sizeof(unsigned int);

    for (unsigned int i = 0; i < bytes; i++)
    {
        unsigned int byte = (n >> (i * 8)) & 0xFFu;                 
        unsigned int mirroredByte = (unsigned int)mirrorLUT[byte];   
        result |= (mirroredByte << ((bytes - 1 - i) * 8));           
    }

    return result;
}





/***************************************************************/






static unsigned char popcntLUT[BYTE_VALUES];
static signed char  kthPosLUT[BYTE_VALUES][9]; 

void BuildThirdBitLUTs(void)
{

    
    for (int v = 0; v < BYTE_VALUES; v++)
    {
        
        unsigned char x = (unsigned char)v;
        unsigned char cnt = 0;
        for (int b = 0; b < 8; b++)
        {
            cnt += (x & 1u);
            x >>= 1;
        }
        popcntLUT[v] = cnt;

        
        for (int k = 0; k <= 8; k++)
            kthPosLUT[v][k] = -1;

        int seen = 0;
        for (int bit = 0; bit < 8; bit++)
        {
            if ( (v >> bit) & 1 )
            {
                seen++;
                kthPosLUT[v][seen] = (signed char)bit; 
            }
        }
    }
}


int IndexOfThirdSetBit_LUT(unsigned int n)
{
    int seen = 0;
    unsigned int bytes = (unsigned int)sizeof(unsigned int);

    for (unsigned int i = 0; i < bytes; i++)
    {
        unsigned int byte = (n >> (i * 8)) & 0xFFu;
        unsigned int pc = popcntLUT[byte];

        if (seen + (int)pc < 3)
        {
            seen += (int)pc;  
        }
        else
        {
            int k = 3 - seen; 
            int posInByte = kthPosLUT[byte][k];
            return (int)(i * 8) + posInByte+1;
        }
    }

    return -1; /* less than 3 set bits */
}


void printBits(unsigned int n)
{
    int totalBits = sizeof(unsigned int) * 8;

    for (int i = totalBits - 1; i >= 0; i--)
    {
        printf("%u", (n >> i) & 1u);
    }

    printf("\n");
}

int main()
{
    unsigned int n;

    BuildBitCountLUT();  
    BuildMirrorLUT(); 

    printf("Enter number:\n");
    scanf("%u", &n);
    printBits(n);
    printf("Answer : %u\n", Majority(n));

    


    printf("Enter number:\n");
    scanf("%u", &n);
    printBits(n);
    printf("Answer: %u\n", BitMirror(n));
    printBits(BitMirror(n));
    printf("LUT:\n");
   
    printf("LUT:\n");


    unsigned int m;
    BuildThirdBitLUTs();

    printf("Enter number: ");
    scanf("%u", &m);
    printBits(m);
    printf("3rd set bit index = %d\n", IndexOfThirdSetBit_LUT(m));

    
    /*
    for (int i = 0; i < BYTE_VALUES; i++)
    {
        printf("bitCountLUT[%d] = %d \n",i ,bitCountLUT[i]);
    }
   
   
    for (int i = 0; i < BYTE_VALUES; i++)
    {
        printf("mirrorLUT[i][%d] = %d \n",i ,mirrorLUT[i]);
    }
    */
    return 0;
}
 
/*
unsigned int Majority(unsigned int n)
{
    int bitcount = 0;
    for (int i = 0; i < sizeof(int)*8; i++)
    {
        if ((n>>i)&1)
        {
            ++bitcount;
        }
    }
    
    if (bitcount > sizeof(int)*4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int main(void)
{
    unsigned int n;

    printf("enter a number: \n");
    scanf("%u",&n);

    printf("is %u have majority of he's bit's turned on?\n 1 if yes\n",n);
    int  x;
    x = Majority(n);
    printf("awnser: %d \n",x);
}*/