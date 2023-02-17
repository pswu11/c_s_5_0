#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid(int height);

int main(void)
{
    int height = get_height();
    print_pyramid(height);
}

// function to print pyramid
void print_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        // left half
        for (int j = 0; j <= height - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        // right half
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        for (int m = 0; m <= height - i; m++)
        {
            printf(" ");
        }
        printf("\n");
    }
}
// get user input for height
int get_height(void)
{
    int height;
    do
    {
        height = get_int("What is the height?\n");
    }
    while (height <= 0);
    return height;
}