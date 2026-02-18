#include <signal.h>

#include <stdio.h>

#include <unistd.h>
int counter=0;

void ohh(int sig)
{
    ++counter;
    printf("    Ohh FUCK! I got a FUCKING signal %d\n", sig);
    if (counter == 3)
    {
        signal(SIGINT, SIG_DFL);
    }    
}

int main()
{
    signal(SIGINT, ohh);
    while(1)
    {
        printf("FUCK YOU!\n");
        sleep(1);
    }
    return 0;
}