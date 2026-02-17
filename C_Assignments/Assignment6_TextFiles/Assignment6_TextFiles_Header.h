#ifndef FILE_MODES_H
#define FILE_MODES_H

#include <stdio.h>

#define FILE_NAME "test.txt"

/*
Description -
Changes the permissions of a file.

Input -
fileName : Path to the file.
perm     : File permission (e.g. 0644, 0444, 0000).

Output -
None.

Error -
PERMISSION_ERROR : chmod failed.
*/
void SetPermissions(const char *fileName, int perm);

/*
Description -
Tries to open a file using a specific fopen mode.

Input -
fileName : Path to the file.
mode     : File open mode ("r", "w", "a", "r+", "w+", "a+").

Output -
None.

Error -
OPEN_FILE_ERROR : fopen returned NULL.
*/
void TryOpen(const char *fileName, const char *mode);

/*
Description -
Attempts to open a file using all fopen modes.

Input -
fileName : Path to the file.

Output -
None.

Error -
OPEN_FILE_ERROR : One or more fopen calls returned NULL.
*/
void OpenAllModes(const char *fileName);





#define PERSONS_FILE "persons.txt"
#define PERSONS_COUNT 5
#define NAME_LEN 30

typedef struct
{
    int id;
    char name[NAME_LEN];
    int age;
} Person;

/*
Description -
Builds 5 persons records with example values.

Input -
persons : Array of Person.
count   : Number of persons in the array.

Output -
None.

Error -
NULL_ARRAY_ERROR : persons is NULL.
SIZE_ERROR       : count is less than or equal to 0.
*/
void BuildPersons(Person persons[], int count);

/*
Description -
Writes persons records to a text file.

Input -
fileName : Path to the file.
persons  : Array of Person.
count    : Number of persons in the array.

Output -
Returns 0 if success.

Error -
NULL_ARRAY_ERROR  : persons is NULL.
SIZE_ERROR        : count is less than or equal to 0.
OPEN_FILE_ERROR   : fopen returned NULL.
WRITE_ERROR       : fprintf failed.
*/
int WritePersonsToFile(const char *fileName, const Person persons[], int count);

/*
Description -
Reads persons records from a text file into an array.

Input -
fileName : Path to the file.
persons  : Array of Person to fill.
count    : Max number of persons to read.

Output -
Returns number of persons read (0..count).

Error -
NULL_ARRAY_ERROR  : persons is NULL.
SIZE_ERROR        : count is less than or equal to 0.
OPEN_FILE_ERROR   : fopen returned NULL.
*/
int ReadPersonsFromFile(const char *fileName, Person persons[], int count);

/*
Description -
Prints persons records to the screen.

Input -
persons : Array of Person.
count   : Number of persons to print.

Output -
None.

Error -
NULL_ARRAY_ERROR : persons is NULL.
SIZE_ERROR       : count is less than or equal to 0.
*/
void PrintPersons(const Person persons[], int count);


/*
Description -
Prints the last N lines of a text file.

Input -
fileName : Path to the file.
n        : Number of last lines to print.

Output -
None.

Error -
OPEN_FILE_ERROR : fopen returned NULL.
SIZE_ERROR      : n is less than or equal to 0.
*/
void PrintLastNLines(const char *fileName, int n);


#endif
