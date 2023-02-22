#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string colors[] = {"black", "red", "orange", "pruple", "gold", "blue", "green"};

    string input = get_string("Color: ");
    for (int i = 0; i < 7; i++)
    {
        if (strcmp(colors[i], input) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

// Segmentation fault:
// when the program is trying to access the index out of bound.
// you touch the segment of memeory that you shouldn't have.