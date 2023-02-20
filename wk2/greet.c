#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[]) // taking a user input as argument.
{
    string name = get_string("What's your name?\n");
    printf("hello, %s\n", name);
    printf("hello, %s\n", argv[1]);
}