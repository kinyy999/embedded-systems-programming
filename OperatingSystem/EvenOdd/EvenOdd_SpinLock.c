#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

#define MAX_NUM 1000


atomic_int turn = 1;

void* print_odd(void* arg)
{
    for (int i = 1; i <= MAX_NUM; i += 2)
    {
        while (atomic_load(&turn) != 1) { } 
        printf("%d\n", i);
        atomic_store(&turn, 0);
    }
    return NULL;
}

void* print_even(void* arg)
{
    for (int i = 2; i <= MAX_NUM; i += 2)
    {
        while (atomic_load(&turn) != 0) { } 
        printf("%d\n", i);
        atomic_store(&turn, 1);
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, print_odd, NULL);
    pthread_create(&t2, NULL, print_even, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
