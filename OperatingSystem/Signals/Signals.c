#include <signal.h>
#include <stdio.h>

int  main()
{
    int sig;
    int id;
    printf("Enter PID\n");
    scanf ("%i", &id );

    printf("Enter signal\n");
    scanf ("%i", &sig);

    printf("Send signal %i to %i\n", sig,id);
    kill (id, sig );

    return 0;
}