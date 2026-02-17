//#include "shellHeader.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


#define MAX_INPUT 1024
  

void type_prompt()
{
    printf("Welcome to  KinyShell, please add your command");
    printf("shellUser:$");
}

void read_command(char *command, char * parameters [])
{

    const char del[]=" \n";
    fgets(command, MAX_INPUT, stdin);
    // {
    //     command[strcspn(command, "\n")] = '\0'; 
    // }
    int i=0;
    char * token = strtok(command, del);
    while(token != NULL)
    {
       parameters[i]= token;
       token = strtok(NULL, del);
       ++i;

    }
    parameters[i]=NULL;

}

int main()
{

    int statusShell = 1;
    char command[MAX_INPUT];
    char*  parameters[MAX_INPUT];
    int status;
    while (1)
    {

        type_prompt();
        read_command(command, parameters);
        if (strcmp(parameters[0], "exit") == 0)
        {

            //statusShell = 0;
            break;
        }

        if (fork() > 0)
        {

            wait(&status);
        }
        else
        {
            execvp(parameters[0],parameters);
            printf("ERR: Command not found\n");
            break;
        }
    }
}