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
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_height(void)
{
    int height = get_int("What is the height?\n");
    return height;
}