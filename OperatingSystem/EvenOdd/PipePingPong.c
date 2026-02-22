#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUF_SIZE 200
#define ROUNDS 5

int main()
{
    int p2c[2];               // parent to child
    int c2p[2];                 // child to parent
    pid_t pid;
    char buf[BUF_SIZE];

    if (pipe(p2c) == -1 )
    {
        perror("pipe");
        exit(1);
    }

    if (pipe(c2p) == -1)
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

    if (pid > 0)  // ===== PARENT =====
    {
        close(p2c[0]);  
        close(c2p[1]); 

        for (int i = 1; i <= ROUNDS; i++)
        {
            sprintf(buf, "Parent message %d", i);
            write(p2c[1], buf, strlen(buf) + 1);

            read(c2p[0], buf, sizeof(buf));
            printf("Parent received: %s\n", buf);
        }

        close(p2c[1]);
        close(c2p[0]);

        wait(NULL);
        printf("Parent exiting.\n");
        exit(0);
    }
    else  // ===== CHILD =====
    {
        close(p2c[1]);  
        close(c2p[0]);  

        for (int i = 1; i <= ROUNDS; i++)
        {
            read(p2c[0], buf, sizeof(buf));
            printf("Child received: %s\n", buf);

            sprintf(buf, "Child reply %d", i);
            write(c2p[1], buf, strlen(buf) + 1);
        }

        close(p2c[0]);
        close(c2p[1]);

        printf("Child exiting.\n");
        exit(0);
    }
}
