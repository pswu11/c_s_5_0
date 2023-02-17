#include <stdio.h>
#include <cs50.h>

int main(void) // main function
{
    string name = get_string("What's your name? \n");
    printf("hello, %s", name);
}
