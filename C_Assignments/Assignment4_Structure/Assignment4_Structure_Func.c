#include <stdio.h>
#include <string.h>
#include "Assignment4_Structure_Headers.h"



void GetPersonData(Person *p)
{
    if (p == NULL)
    {
        return;
    }

    printf("Enter name: ");
    scanf(" %29s", p->name);   /* שים לב לרווח לפני %29s */

    printf("Enter ID: ");
    if (scanf(" %d", &p->id) != 1) return;

    printf("Enter age: ");
    if (scanf(" %d", &p->age) != 1) return;

    printf("Enter education: ");
    if (scanf(" %d", &p->education) != 1) return;
}


void PrintPersonData(const Person *p)
{
    if (p == NULL)
    {
        return;
    }

    printf("Name: %s\n", p->name);
    printf("ID: %d\n", p->id);
    printf("Age: %d\n", p->age);
    printf("Education: %d\n", p->education);
}

/* Step 3: Swap two Persons */
static void SwapPersons(Person *a, Person *b)
{
    Person tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Step 4: Efficient Bubble Sort by Age (ascending) */
void BubbleSortByAge(Person arr[], int n)
{
    int i, j;
    int swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j].age > arr[j + 1].age)
            {
                SwapPersons(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }
}

/* Step 5: Efficient Bubble Sort by Name (A-Z) */
void BubbleSortByName(Person arr[], int n)
{
    int i, j;
    int swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for (j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0)
            {
                SwapPersons(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }
}

