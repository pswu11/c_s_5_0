#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? \n");
    printf("hello, %s\n", name);
}

// compile in codespace:
// make hello
// ./hello

// compile locally:
// clang hello.c -o hello -lcs50