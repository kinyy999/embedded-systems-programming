#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 100
#define TRUE 1
#define SIZE 500
//typedef int semaphore;

//semaphore mutex = 1;
//semaphore empty = N;
//semaphore full  = 0;

//sem_t mutex;
sem_t empty;
sem_t full;

pthread_mutex_t mutex;

int counter=0;

void insert_item()
{
    ++counter;
    printf("Insert Counter: %d\n", counter);
}
int remove_item(void)
{
    --counter;
    printf("Remove Counter: %d\n", counter);
}

void* producer(void* tid)
{
    for(int i=0;i<SIZE+10;++i) 
    {
        sem_wait(&empty);
        //sem_wait(&mutex);
        pthread_mutex_lock(&mutex);
        insert_item();
        pthread_mutex_unlock(&mutex);
        //sem_post(&mutex);
        sem_post(&full);
    }
    pthread_exit(NULL);
}

void* consumer(void* tid)
{
    for(int i=0;i<SIZE;++i) 
    {
        sem_wait(&full);
        //sem_wait(&mutex);
        pthread_mutex_lock(&mutex);
        remove_item();
        pthread_mutex_unlock(&mutex);
        //sem_post(&mutex);
        sem_post(&empty);
    }
    pthread_exit(NULL);
}


int main()
{
    pthread_t produce, consum;

    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    
    //sem_init(&mutex,0,1);
    sem_init(&empty,0,N);
    sem_init(&full,0,0);
    
    pthread_create(&produce,NULL,producer, NULL);
    pthread_create(&consum,NULL,consumer, NULL);

    pthread_join(produce,NULL);
    pthread_join(consum,NULL);

    pthread_mutex_destroy(&mutex);
    //sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    
    return 0;

}