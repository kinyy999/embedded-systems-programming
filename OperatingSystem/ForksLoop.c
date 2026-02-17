#include<stdio.h> 
#include <unistd.h>   
#include <sys/types.h>

int g_var = 0;

int main()
{
    int l_var=0;

    pid_t n = fork();

    if (n>0) 
    {
        //wait();
        sleep(20);

        for (int i = 0; i < 30; i++)
        {
            ++g_var; 
            ++l_var; 
            printf("l_var %d g_var %d\n" ,l_var ,g_var);
        }
    }
     else
    {
        
        sleep(10);
        
        for (int i = 0; i < 30; i++)
        {
            --g_var; 
            --l_var; 
            printf("l_var %d g_var %d\n" ,l_var ,g_var);
        }
    }
}

//ps -n