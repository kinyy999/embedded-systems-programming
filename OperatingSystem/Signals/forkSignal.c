#include<stdio.h> 
#include <unistd.h>   
#include <sys/types.h>
#include <signal.h>

int main()
{
    pid_t n = fork();

    if (n>0) 
    {
        //wait();
        sleep(3);
        kill(0, SIGTTIN);
    }   
     else
    {
        while(1)
        {            
            printf("i am son of a bitch \n");
        }
    }
}
