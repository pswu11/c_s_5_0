#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid(int height);
int main(void)
{
    int height = get_height();
    print_pyramid(height);
}

void print_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= height - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        print("  ");
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

int get_height(void)
{
    int height = get_int("What is the height?\n");
    return height;
}