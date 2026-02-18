#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define MAX_NUM 1000

sem_t sem_odd;
sem_t sem_even;

void* print_odd(void* arg)
{
    for (int i = 1; i <= MAX_NUM; i += 2)
    {
        sem_wait(&sem_odd);          
        printf("%d\n", i);           
        sem_post(&sem_even);        
    }
    return NULL;
}

void* print_even(void* arg)
{
    for (int i = 2; i <= MAX_NUM; i += 2)
    {
        sem_wait(&sem_even);       
        printf("%d\n", i);           
        sem_post(&sem_odd);         
    }
    return NULL;
}

int main()
{
    pthread_t t_odd, t_even;

    sem_init(&sem_odd, 0, 1);
    sem_init(&sem_even, 0, 0);

    if (pthread_create(&t_odd, NULL, print_odd, NULL) != 0)
    {
        perror("pthread_create odd");
        exit(1);
    }

    if (pthread_create(&t_even, NULL, print_even, NULL) != 0)
    {
        perror("pthread_create even");
        exit(1);
    }

    pthread_join(t_odd, NULL);
    pthread_join(t_even, NULL);

    sem_destroy(&sem_odd);
    sem_destroy(&sem_even);

    return 0;
}
