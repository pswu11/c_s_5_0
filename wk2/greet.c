#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[]) // taking a user input as arguments.
{
    // string name = get_string("What's your name?\n");
    // printf("hello, %s\n", name);
    // printf("hello, %s\n", argv[1]);
    // why 1 here?
    // it turns out that when we send "./greet Pei"
    // "./greet" => argv[0] ; "Pei" => argv[1]
    printf("The length is: %i\n", argc);

    if (argc <= 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world!\n"); // default if only one argument was given
    }

    printf("    _____\n   /     \\______\n  | o     |\n     \\____\n  /\\_____/           \\___\n /                       \\\n|_______/                 \\\n  \\______   _       ___    \\\n        /\\_//      /   \\    |\n       // //______/    /___/\n      /\\/\\/\\      \\   / \\ \\\n                    \\ \\   \\ \\\n                      \\ \\   \\ \\\n                        \\ \\  \\ \\\n                         \\ \\ /\\/\\\n                         /\\/\\\n");
}

// cowsay
