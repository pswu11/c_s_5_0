#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");
    // scanf takes a pointer to the variable you want to store the input
    // in, so you need to use the & operator to get the address of x
    scanf("%i", &x);
    printf("user input: %i\n", x);
}