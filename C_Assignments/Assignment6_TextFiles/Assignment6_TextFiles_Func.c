#include "Assignment6_TextFiles_Header.h"
#include <sys/stat.h>

/*
Description -
Changes the permissions of a file.
*/
void SetPermissions(const char *fileName, int perm)
{
    if (chmod(fileName, perm) == 0)
    {
        printf("\nPermissions changed to %04o\n", perm);
    }
    else
    {
        printf("\nPERMISSION_ERROR\n");
    }
}

/*
Description -
Tries to open a file using a specific fopen mode.
*/
void TryOpen(const char *fileName, const char *mode)
{
    FILE *fp = fopen(fileName, mode);

    if (fp == NULL)
    {
        printf("mode %-2s -> fopen returned NULL\n", mode);
        return;
    }

    printf("mode %s -> opened successfully\n", mode);

    fclose(fp);
}

/*
Description -
Attempts to open a file using all fopen modes.
*/
void OpenAllModes(const char *fileName)
{
    TryOpen(fileName, "r");
    TryOpen(fileName, "w");
    TryOpen(fileName, "a");
    TryOpen(fileName, "r+");
    TryOpen(fileName, "w+");
    TryOpen(fileName, "a+");
}



/*
Description -
Builds 5 persons records with example values.
*/
void BuildPersons(Person persons[], int count)
{
    int i;

    if (persons == NULL)
    {
        return;
    }

    if (count <= 0)
    {
        return;
    }

    
    for (i = 0; i < count; i++)
    {
        persons[i].id = 100 + i;
        persons[i].age = 20 + i;

        /* names must be <= NAME_LEN-1 */
        if (i == 0) { snprintf(persons[i].name, NAME_LEN, "Dan"); }
        if (i == 1) { snprintf(persons[i].name, NAME_LEN, "Noa"); }
        if (i == 2) { snprintf(persons[i].name, NAME_LEN, "Avi"); }
        if (i == 3) { snprintf(persons[i].name, NAME_LEN, "Maya"); }
        if (i == 4) { snprintf(persons[i].name, NAME_LEN, "Rami"); }
    }
}

/*
Description -
Writes persons records to a text file.
*/
int WritePersonsToFile(const char *fileName, const Person persons[], int count)
{
    FILE *fp;
    int i;

    if (persons == NULL)
    {
        return -1; /* NULL_ARRAY_ERROR */
    }

    if (count <= 0)
    {
        return -2; /* SIZE_ERROR */
    }
     
    fp = fopen(fileName, "w");
    if (fp == NULL)
    {   
        perror("fopen");
        return -3; /* OPEN_FILE_ERROR */
    }

    /* each line: id name age */
    for (i = 0; i < count; i++)
    {
        if (fprintf(fp, "%d %s %d\n", persons[i].id, persons[i].name, persons[i].age) < 0)
        {
            fclose(fp);
            return -4; /* WRITE_ERROR */
        }
    }

    fclose(fp);
    return 0;
}

/*
Description -
Reads persons records from a text file into an array.
*/
int ReadPersonsFromFile(const char *fileName, Person persons[], int count)
{
    FILE *fp;
    int readCount = 0;

    if (persons == NULL)
    {
        return -1; /* NULL_ARRAY_ERROR */
    }

    if (count <= 0)
    {
        return -2; /* SIZE_ERROR */
    }

    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        return -3; /* OPEN_FILE_ERROR */
    }

    /* Read until fail or reach count */
    while (readCount < count)
    {
        int res = fscanf(fp, "%d %29s %d",
                         &persons[readCount].id,
                         persons[readCount].name,
                         &persons[readCount].age);

        if (res != 3)
        {
            break; /* EOF or wrong format */
        }

        readCount++;
    }

    fclose(fp);
    return readCount;
}

/*
Description -
Prints persons records to the screen.
*/
void PrintPersons(const Person persons[], int count)
{
    int i;

    if (persons == NULL)
    {
        return;
    }

    if (count <= 0)
    {
        return;
    }

    printf("\n--- Persons ---\n");
    for (i = 0; i < count; i++)
    {
        printf("ID: %d | Name: %s | Age: %d\n",
               persons[i].id, persons[i].name, persons[i].age);
    }
}



void PrintLastNLines(const char *fileName, int n)
{
    FILE *fp;
    char line[256];
    int totalLines = 0;
    int startLine;
    int currentLine = 0;

    if (n <= 0)
    {
        return;
    }

    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("OPEN_FILE_ERROR\n");
        return;
    }

    /* Count total lines */
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        totalLines++;
    }

    startLine = totalLines - n;
    if (startLine < 0)
    {
        startLine = 0;
    }

    rewind(fp);

    /* Print last N lines */
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (currentLine >= startLine)
        {
            printf("%s", line);
        }
        currentLine++;
    }

    fclose(fp);
}
