#include <stdio.h>
#include "Arrays_Headers.h"

int main(void)
{
    int arr_avg[] = {10, 20, 30, 40, 50};

    /*  Valid array
        NULL array 
        Negative size 
    */
    printf("Valid array result: %d\n", ArrayAverage(arr_avg, 5));
    printf("NULL array result: %d\n", ArrayAverage(NULL, 5));
    printf("Negative size result: %d\n", ArrayAverage(arr_avg, -3));


    

    /*
    Case 1: valid input
    Case 2: negative input
    */
   
    int result_fac;
    result_fac = Factorial(5);
    printf("Factorial(5) = %d\n", result_fac);
    result_fac = Factorial(-5);
    printf("Factorial(-5) = %d\n", result_fac);


    /* 
    Case 1: palindrome number
    Case 2: non-palindrome number
    Case 3: negative number (converted to positive inside func)
    */
    printf("IsPalindrome(12321) = %d\n", IsPalindrome(12321));
    printf("IsPalindrome(12345) = %d\n", IsPalindrome(12345));
    printf("IsPalindrome(-1221) = %d\n", IsPalindrome(-1221));


    /* 
    Case 1: ascending order number
    Case 2: non-ascending order number
    Case 3: negative ascending order number (converted to positive inside func)
    */   

    printf("IsAscendingDigits(1234) = %d\n", IsAscendingDigits(1234));
    printf("IsAscendingDigits(1324) = %d\n", IsAscendingDigits(1324));
    printf("IsAscendingDigits(-4567) = %d\n", IsAscendingDigits(-4567));    


    /*
    Case 1: is prime number
    Case 2: non-prime number
    Case 3&4: 1 and 2 number
    */ 

    printf("IsPrime(7) = %d\n", IsPrime(7));
    printf("IsPrime(9) = %d\n", IsPrime(9));
    printf("IsPrime(1) = %d\n", IsPrime(1));
    printf("IsPrime(2) = %d\n", IsPrime(2));


    /*
    Case 1: reversed postive number
    Case 2: reversed negative number
    */ 

    printf("ReverseNumber(1234) = %d\n", ReverseNumber(1234));
    printf("ReverseNumber(-508) = %d\n", ReverseNumber(-508));


    /*
    Case 1: diffrent place 
    Case 2: same place
    Case : number should have diifrent digits
    */ 
    printf("Result (1234 , 4321) = %d\n", CheckDigitsMatch(1234, 4321));
    printf("Result (2468 , 2648) = %d\n", CheckDigitsMatch(2468, 2648));
    printf("Result (1123 , 3211) = %d\n", CheckDigitsMatch(1123, 3211));

    return 0;
}
