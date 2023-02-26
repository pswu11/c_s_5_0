#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 50;
    // int *p => means it's a variables (aka "pointer") that contains
    // the address of an integer, it's still an int (usually 8 bytes).
    // int p => means it's a variable of integer.
    // &n => it returns the address of variable n.
    // so below we're assigning the address of n to p.
    int *p = &n;
    // %p => allow us to print an address
    // no need to use *p here
    printf("%p\n", p); //=> print the address of n
    printf("%i\n", *p); //=> go to the address that p stores and find the value of n
    // String
    // the pointer of a string only saves the address of the first charactor
    string s = "Hi!"; // which is actually saved as array like H, i, !, \0
    // string is actually array of char in memory string => char *string
    // without a CS50 library, you can't use string type directly,
    // instead:
    char *s2 = "Hi!";
    printf("%p\n", s2);
}

// n is saved somewhere in our memory
// since it's an integer, so it's gonna use 4 bytes
// memory management is powerful but could also cause
// more segmantation fault.

// # Operators:
// ampersand (&): allow us to get the address of piece of data in memory
// c will tell us what address this varialbe lives on
// star (*): dereference, go to a specific addresss

// # Pointers:
// it's one of the challenging topic to learn and it's not used in high-level
// programming languages.
// an integer variable that contains/represents the address of another variable.
// Why do we use pointers?
// It;s like the mailbox (p, which contains address) pointing to (n, which contains actual value).
