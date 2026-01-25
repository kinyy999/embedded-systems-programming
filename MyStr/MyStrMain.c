#include <stdio.h>
#include "MyStrHeader.h"
#define OK                    1
#define NOT_OK                0

#define NULL_STRING_ERROR    -1
#define NULL_BUFFER_ERROR    -2
#define NEGATIVE_N_ERROR     -3
#define INVALID_FORMAT_ERROR -4


int main()
{
    char str[] = "hello";

    int len = MyStrlen(str);
    printf("Length = %d\n", len);

    
    
    char s1[20] = "Hello";
    char s2[] = "World";

    MyStrncat(s1, s2, 3);

    printf("%s\n", s1);  // HelloWor



    printf("%d\n", MyStrcmp("abc", "abc"));   // 0
    printf("%d\n", MyStrcmp("abc", "abd"));   // <0
    printf("%d\n", MyStrcmp("dog", "cat"));   // >0



    printf("%d\n", MyStrncmp("abc", "abd", 2)); // 0
    printf("%d\n", MyStrncmp("abc", "abd", 3)); // <0
    printf("%d\n", MyStrncmp("dog", "cat", 1)); // >0


    char str4[] = "hello";

    if (ReverseStr(str) == OK)
    {
        printf("Reversed string: %s\n", str);
    }
    else
    {
        printf("Error reversing string\n");
    }



    char str5[] = "abccba";

    int r = IsPalindrome(str5);
    if (r == 0) printf("the %s is Palindrome\n", str5);
    else if (r == -1) printf("the %s isn't Palindrome\n", str5);
    else printf("NULL error\n");

    
    int num;

    if (MyAToI("  -456", &num) == OK)
    {
        printf("Number = %d\n", num);
    }
    else
    {
        printf("Error\n");
    }

    char buf[20];

    if (MyIToA(-12345, buf) == OK)
    {
        printf("String = %s\n", buf);
    }
    else
    {
        printf("Error\n");
    }

    return 0;
}
