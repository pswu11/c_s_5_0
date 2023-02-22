#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = get_int("Height: ");
    draw(height);

}

void draw(int n)
{
    draw(n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
    // draw(n+1); infinite recursion.

}