#include <stdio.h>

#define BUF_SIZE 250


int main()
{
    FILE *fp1, *fp2;
    char buf[BUF_SIZE];

    fp1 = popen("ls -l","r");
    fp2 = popen("wc", "w");

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("ERROR in open pipe\n") ;
        return -1 ;

    }
    
    while (fgets(buf,BUF_SIZE-1,fp1) != NULL)
    {
        fputs(buf,fp2) ;
    }
    pclose(fp1) ;
    pclose(fp2) ;

    return 0;
}