 #include <stdio.h>

 int main(void)
 {
    int n = 50;
    // int *p => means it's a variables (aka "pointer") that contains the address of an integer.
    // int p => means it's a variable of integer.
    // &n => it returns the address of variable n.
    // so below we're assigning the address of n to p.
    int *p = &n;
    // %p => allow us to print an address
    // no need to use *p here
    printf("%p\n", p);
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
// a variable that contains an address of a variable.
