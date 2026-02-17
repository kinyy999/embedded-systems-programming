#include "Assignment6_TextFiles_Header.h"

/*
Description -
Creates a file, changes its permissions and tests fopen
with all file open modes.

Input -
None.

Output -
Returns 0 on success.

Error -
FILE_CREATE_ERROR : Failed to create the file.
*/
int main(void)
{
    FILE *fp;   
    SetPermissions(FILE_NAME, 0644);

    /* Create file so r and r+ can work */
    fp = fopen(FILE_NAME, "w+");
    if (fp == NULL)
    {
        printf("FILE_CREATE_ERROR\n");
        return 1;
    }
    fclose(fp);

    printf("==== Permissions 0644 ====\n");
    SetPermissions(FILE_NAME, 0644);
    OpenAllModes(FILE_NAME);

    printf("\n==== Permissions 0444 (read only) ====\n");
    SetPermissions(FILE_NAME, 0444);
    OpenAllModes(FILE_NAME);

    printf("\n==== Permissions 0000 (no permissions) ====\n");
    SetPermissions(FILE_NAME, 0000);
    OpenAllModes(FILE_NAME);



    


    Person persons[PERSONS_COUNT];
    Person personsFromFile[PERSONS_COUNT];
    int readCount;

    /* Build 5 person records */
    BuildPersons(persons, PERSONS_COUNT);
    printf("PERSONS_FILE = %s\n", PERSONS_FILE);

    /* Open file + write persons + close */
    if (WritePersonsToFile(PERSONS_FILE, persons, PERSONS_COUNT) != 0)
    {
        printf("FILE_WRITE_ERROR\n");
        return 1;
    }

    /* Check file exists + view data is correct:
       (Course level check = open with "r" and print the raw file) */
    printf("\nFile check (raw view):\n");
    {
        FILE *fp = fopen(PERSONS_FILE, "r");
        int ch;

        if (fp == NULL)
        {
            printf("OPEN_FILE_ERROR\n");
            return 1;
        }

        while ((ch = fgetc(fp)) != EOF)
        {
            putchar(ch);
        }
        
        fclose(fp);
    }

    /* Open file + read persons + print them */
    readCount = ReadPersonsFromFile(PERSONS_FILE, personsFromFile, PERSONS_COUNT);
    if (readCount < 0)
    {
        printf("FILE_READ_ERROR\n");
        return 1;
    }

    PrintPersons(personsFromFile, readCount);

    printf("\nLast 3 lines:\n");
    PrintLastNLines(PERSONS_FILE, 3);


    return 0;
}
