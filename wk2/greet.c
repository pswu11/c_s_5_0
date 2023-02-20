#include <stdio.h>
#include <cs50.h>

// taking a user input as arguments.
// int is always with main
// means main always return an int.
int main(int argc, string argv[])
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
    // print a nice frog
    printf("    _____\n   /     \\______\n  | o     |     \\____\n  /\\_____/           \\___\n /                       \\\n|_______/                 \\\n  \\______   _       ___    \\\n        /\\_//      /   \\    |\n       // //______/    /___/\n      /\\/\\/\\      \\   / \\ \\\n                    \\ \\   \\ \\\n        Pei Pei       \\ \\   \\ \\\n                        \\ \\  \\ \\\n                         \\ \\ /\\/\\\n                         /\\/\\\n");
}

// cowsay -f duck  quack!

// 404:
// a kind of error
// use "echo $?" to find out the exit status of the last command
// which will be the int that was returned in the main function.


// Cryptography:
// an algorithm to encrypt a normal text into ciphertext.
