#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define BUF_SIZE 200
#define SLEEP_SEC 5

int main()
{
    int p1[2];                 
    pid_t pid;
    char buf[BUF_SIZE];
    char msg[] = "Fucking Finished,Fucking close me";

    if (pipe(p1) == -1)
    {
        perror("pipe");
        exit(1);
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }

    if (pid > 0)   
    {
        close(p1[1]);  

        if (read(p1[0], buf, sizeof(buf)) > 0)
        {
            printf("a Fucking Parent : received a Fucking message: %s\n", buf);
            printf("a Fucking Parent : closing a Fucking child and exiting...\n");
        }

        close(p1[0]);   

        kill(0,SIGINT);     

        exit(0);
    }
    else          
    {
        close(p1[0]);  

        printf("a Fucking Child: Fucking sleeping %d seconds...\n", SLEEP_SEC);
        sleep(SLEEP_SEC);

       
        write(p1[1], msg, sizeof(msg));

        close(p1[1]); 
        exit(0);
    }
}
