#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int colors[] = {"black", "red", "orange", "pruple", "gold", "blue", "green"};

    int n = get_string("Color: ");
    for (int i = 0; i < 7; i++)
    {
        if (strcmp(colors[i], n))
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}