#include <stdio.h>
#include <cs50.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);

}

void draw(int n)
{
    if (n <= 0)
    {
        return;
    }

    draw(n-1); // recursion

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
    // draw(n+1); infinite recursion.

}