#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 60000
#define RANGE 100000

/* ---------- MACRO ---------- */
#define SWAP_MACRO(a, b)   \
    do {                   \
        int t = (a);       \
        (a) = (b);         \
        (b) = t;           \
    } while (0)

/* ---------- ARRAYS ---------- */
static int src[N];
static int work[N];

void fill_random(void)
{
    for (int i = 0; i < N; i++)
        src[i] = rand() % RANGE;
}

void reset_work(void)
{
    memcpy(work, src, sizeof(src));
}


void swap_func(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


void bubble_func(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap_func(&arr[j], &arr[j + 1]);
}


void bubble_macro(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                SWAP_MACRO(arr[j], arr[j + 1]);
}

int main(void)
{
    clock_t start, end;
    double t_func, t_macro, percent;

    srand(1);
    fill_random();

    /* ---- Attempt 1: function ---- */
    reset_work();
    start = clock();
    bubble_func(work, N);
    end = clock();
    t_func = (double)(end - start) / CLOCKS_PER_SEC;

    /* ---- Attempt 2: macro ---- */
    reset_work();
    start = clock();
    bubble_macro(work, N);
    end = clock();
    t_macro = (double)(end - start) / CLOCKS_PER_SEC;

    /* ---- Results ---- */
    printf("Swap FUNCTION time: %.3f seconds\n", t_func);
    printf("Swap MACRO time   : %.3f seconds\n", t_macro);

    percent = (t_func - t_macro) / t_func * 100.0;

    if (percent > 0)
        printf("MACRO is faster by %.2f%%\n", percent);
    else
        printf("FUNCTION is faster by %.2f%%\n", -percent);

    return 0;
}





















/*


#include <stdio.h>


int StrToInt(const char *str)
{
    int num = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }

    return num;
}

int main(int argc, char *argv[])
{
    


    if (argc < 3)
    {
        printf("Missing parameter\n");
        return 1;
    }

    
    printf("zero parameter: %s\n", argv[0]);
    printf("First parameter: %s\n", argv[1]);
    printf("Second parameter: %s\n", argv[2]);

    
    int num1 = StrToInt(argv[1]);
    int num2 = StrToInt(argv[2]);

    
    printf("Sum: %d\n", num1 + num2);
    printf("Multiply: %d\n", num1 * num2);

    return 0;
}
*/