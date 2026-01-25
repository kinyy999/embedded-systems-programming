#include <stdio.h>
#define OK                    1
#define NOT_OK                0

#define NULL_STRING_ERROR    -1
#define NULL_BUFFER_ERROR    -2
#define NEGATIVE_N_ERROR     -3
#define INVALID_FORMAT_ERROR -4


/* Flags for what to validate */
#define CHECK_S1        (1 << 0)   /* s1 (string) must not be NULL */
#define CHECK_S2        (1 << 1)   /* s2 (string) must not be NULL */
#define CHECK_OUT_PTR   (1 << 2)   /* output int pointer must not be NULL */
#define CHECK_BUFFER    (1 << 3)   /* buffer pointer must not be NULL */
#define CHECK_N_NONNEG  (1 << 4)   /* n must be >= 0 */


int CheckParameters(const char *s1, const char *s2, const int *out, const char *buf, int n, int flags)
{
    if ((flags & CHECK_S1) && s1 == NULL)
        return NULL_STRING_ERROR;

    if ((flags & CHECK_S2) && s2 == NULL)
        return NULL_STRING_ERROR;

    if ((flags & CHECK_OUT_PTR) && out == NULL)
        return INVALID_FORMAT_ERROR; /* reuse your existing code for "invalid" pointer */

    if ((flags & CHECK_BUFFER) && buf == NULL)
        return NULL_BUFFER_ERROR;

    if ((flags & CHECK_N_NONNEG) && n < 0)
        return NEGATIVE_N_ERROR;

    return OK;
}



int MyStrlen(char str[])
{
    int count = 0;
    

    /* Check parameters using general function */
    int check_res = CheckParameters(str, NULL, NULL, NULL, 0, CHECK_S1);
    if (check_res != OK)
        return check_res;

    while (str[count] != '\0')
    {
        count++;
    }

    return count;
}


char* MyStrncat(char *s1, const char *s2, int n)
{
    int i = 0;
    int j = 0;
    

    /* Check parameters using general function */
    int check_res = CheckParameters(s1, s2, NULL, NULL, n, CHECK_S1 | CHECK_S2 | CHECK_N_NONNEG);
    if (check_res != OK)
        return NULL;

    while (s1[i] != '\0')
    {
        i++;
    }

    while (s2[j] != '\0' && j < n)
    {
        s1[i] = s2[j];
        i++;
        j++;
    }

    s1[i] = '\0';

    return s1;
}



int MyStrcmp(const char *s1, const char *s2)
{
    int i = 0;

    /* Check parameters using general function */
    int check_res = CheckParameters(s1, s2, NULL, NULL, 0, CHECK_S1 | CHECK_S2);
    if (check_res != OK)
        return check_res;

    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];

        i++;
    }

    return s1[i] - s2[i];
}


int MyStrncmp(const char *s1, const char *s2, int n)
{
    int i = 0;

    /* Check parameters using general function */
    int check_res = CheckParameters(s1, s2, NULL, NULL, n,CHECK_S1 | CHECK_S2 | CHECK_N_NONNEG);
    if (check_res != OK)
        return check_res;

    while (i < n && s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];

        i++;
    }

    if (i == n)
        return 0;

    return s1[i] - s2[i];
}



int ReverseStr(char *_str)
{

    /* Check parameters using general function */
    int check_res = CheckParameters(_str, NULL, NULL, NULL, 0, CHECK_S1);
    if (check_res != OK)
        return check_res;

    char *left = _str;
    char *right = _str;

    /* move right to end of string */
    while (*right != '\0')
        right++;

    right--;   /* last valid character */

    /* swap from outside to inside */
    while (left < right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }

    return OK;
}

int IsPalindrome(char *_str)
{
    /* Check parameters using general function */
    int check_res = CheckParameters(_str, NULL, NULL, NULL, 0, CHECK_S1);
    if (check_res != OK)
        return check_res;


    if (_str == NULL)
        return NULL_STRING_ERROR;

    char *left = _str;
    char *right = _str;

    
    while (*right != '\0')
        right++;

    if (right == _str)      
        return OK;

    right--;                

    while (left < right)
    {
        if (*left != *right)
            return NOT_OK;

        left++;
        right--;
    }

    return OK;
}

int MyAToI(char *_str, int *_num)
{
    int sign = 1;
    int result = 0;

    /* Check parameters using general function */
    int check_res = CheckParameters(_str, NULL, _num, NULL, 0, CHECK_S1 | CHECK_OUT_PTR);
    if (check_res != OK)
        return check_res;


    /* skip leading spaces */
    while (*_str == ' ')
        _str++;

    /* handle sign */
    if (*_str == '-')
    {
        sign = -1;
        _str++;
    }
    else if (*_str == '+')
    {
        _str++;
    }

    /* must start with digit */
    if (*_str < '0' || *_str > '9')
        return NOT_OK;

    /* convert digits */
    while (*_str >= '0' && *_str <= '9')
    {
        result = result * 10 + (*_str - '0');
        _str++;
    }

    *_num = result * sign;
    return OK;
}


int MyIToA(int _num, char *_buffer)
{
    int i = 0;
    int sign = 1;
    

    /* Check parameters using general function */
    int check_res = CheckParameters(NULL, NULL, NULL, _buffer, 0, CHECK_BUFFER);
    if (check_res != OK)
        return check_res;

    /* special case: 0 */
    if (_num == 0)
    {
        _buffer[0] = '0';
        _buffer[1] = '\0';
        return OK;
    }

    /* handle sign */
    if (_num < 0)
    {
        sign = -1;
        _num = -_num;
    }

    /* extract digits (reverse order) */
    while (_num > 0)
    {
        _buffer[i++] = (_num % 10) + '0';
        _num /= 10;
    }

    /* add minus sign if needed */
    if (sign == -1)
        _buffer[i++] = '-';

    _buffer[i] = '\0';

    /* reverse the string in buffer */
    int left = 0;
    int right = i - 1;
    while (left < right)
    {
        char temp = _buffer[left];
        _buffer[left] = _buffer[right];
        _buffer[right] = temp;

        left++;
        right--;
    }

    return OK;
}
