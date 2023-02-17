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
        // left half of pyramid
        for (int j = height - 1; j > i; j--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        // the gap
        printf("  ");
        // right half of pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
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
    while (height <= 0 || height > 8); // the height should be between 
    return height;
}