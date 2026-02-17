#ifndef PERSON_H
#define PERSON_H

/*
 * Struct Name: Person
 * -------------------
 * Description:
 * This structure represents a person and contains personal information.
 *
 * Members:
 * name      - Person name
 * id        - Person ID number
 * age       - Person age
 * education - Person education level
 */
typedef struct
{
    char name[30];
    int id;
    int age;
    int education;
} Person;
union un
{
    int numOfToys;
    float money;
};

struct person
{
    int age;
    union un u;
    char name[32];
};



/*
 * Function Name: GetPersonData
 * ----------------------------
 * Description:
 * This function receives a pointer to a Person structure and
 * reads the person's data from the keyboard.
 *
 * Input:
 * p - Pointer to Person structure
 *
 * Output:
 * None
 *
 * Return:
 * None
 */
void GetPersonData(Person *p);


/*
 * Function Name: PrintPersonData
 * ------------------------------
 * Description:
 * This function receives a pointer to a Person structure and
 * prints the person's data.
 *
 * Input:
 * p - Pointer to Person structure
 *
 * Output:
 * Printed person data
 *
 * Return:
 * None
 */
void PrintPersonData(const Person *p);

#endif /* PERSON_H */
