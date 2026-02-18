#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>



sem_t mutex;


#define NUM_OF_THREADS   10
#define NUMBER_OF_ITER   10000  
int g_num = 0;  


void* PrintFunc(void* tid)
{
    int thread_num = *(int*)tid;   
    int l_num = 0;                

    for (int j = 0; j < NUMBER_OF_ITER; j++)
    {
        l_num++; 
        //sem_wait(&mutex);     
        g_num++;   
        //sem_post(&mutex);


        if (j % 250000 == 0)
        {
            printf("thread:%d  j:%d  local:%d  global:%d\n",
                   thread_num, j, l_num, g_num);
        }
    }

    printf("DONE thread:%d  local:%d  global:%d\n",
           thread_num, l_num, g_num);

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_OF_THREADS];
    int indx[NUM_OF_THREADS];
    //sem_init(&mutex,0,1);
    for (int i = 0; i < NUM_OF_THREADS; i++)
    {
        indx[i] = i;
        
        int status = pthread_create(&threads[i],NULL,PrintFunc,(void*)&indx[i]);
        


        if (status != 0)
        {
            printf("Error: pthread_create failed for i=%d (status=%d)\n", i, status);
            exit(1);
        }
    }

    for (int i = 0; i < NUM_OF_THREADS; i++)
    {
        int status = pthread_join(threads[i], NULL);
        if (status != 0)
        {
            printf("Error: pthread_join failed for i=%d (status=%d)\n", i, status);
            exit(1);
        }
    }

    printf("\nExpected global = %d\n", NUM_OF_THREADS * NUMBER_OF_ITER);
    printf("Actual   global = %d\n", g_num);
    //sem_destroy(&mutex);

    return 0;
}
