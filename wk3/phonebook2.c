#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Custom data structure: define a new struct type
typedef struct
{
    string name;
    string number;
}
person; // This is the name of the customed struct type

int main(void)
{
    person contacts[2];
    // In reality, the below part would be
    // reading and writing from a database.
    contacts[0].name = "Carter";
    contacts[0].number = "+49-152-38965479";
    contacts[1].name = "David";
    contacts[1].number = "+886-911-333335";

    string input = get_string("Name: ");
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(contacts[i].name, input) == 0)
        {
            printf("Found %s: %s\n", contacts[i].name, contacts[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

