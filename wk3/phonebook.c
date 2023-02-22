#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Carter", "David"};
    // if you want to have both name and numbers
    // get another array or use 2D array.
    string numbers[] = {"+49-152-38965479", "+886-911-333335"};

    string input = get_string("Name: ");
    for (int i = 0; i < 1; i++)
    {
        if (strcmp(names[i], input) == 0)
        {
            printf("Found %s: %s\n", names[i], numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;

}