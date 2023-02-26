 #include <stdio.h>

 int main(void)
 {
    int n = 50;
    // %p => allow us to print an address
    printf("%p\n", &n);
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


