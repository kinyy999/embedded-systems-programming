#include <stdio.h>

#include <pthread.h>

#include <stdatomic.h>

// making an atomic counter

_Atomic int atomic_count = 0;

// making a simple variable

int count = 0;

// the function which will run in the thread

void* runner(){

for(int i = 0; i < 100000; i++) {

count++;

atomic_count++;

}

return 0 ;

}

int main(){

// making the essential variables to create threads

pthread_t threadIDs[50];

pthread_attr_t attr;

pthread_attr_init(&attr);

// making 50 threads

for(int i = 0; i < 50; i++) {

pthread_create(&threadIDs[i], NULL, runner, NULL);

}

// waiting for all threads to finish

for(int i = 0; i < 50; i++) {

pthread_join(threadIDs[i], NULL);

}

// printing the variables

printf("The atomic counter is %u\n", atomic_count);

printf("The non-atomic counter is %u\n", count);

}