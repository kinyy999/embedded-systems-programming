#include "Assignment4_Structure_Headers.h"
#include <stdio.h>
 


int main(void)
{
   /*
    Person person1;
    Person *pPerson1 = &person1;

    GetPersonData(pPerson1);
    PrintPersonData(pPerson1);
        

    Person persons[3] = {0};
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("\n--- Person %d ---\n", i + 1);
         etPersonData(&persons[i]);
    }

    for (i = 0; i < 3; i++)
    {
        printf("\n--- Print Person %d ---\n", i + 1);
        PrintPersonData(&persons[i]);
    }
    */
   struct person p;

    p.u.numOfToys = 5;

    p.u.money = 4015.54;
    printf("%p \n",(void* )&p.u.numOfToys);
    printf("%p \n",(void* )&p.u.money);

    return 0;
}

