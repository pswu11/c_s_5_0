#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");

    string t = s;
    // above line assigns t with memory address of s;
    // hence both t and s points to the same address.

    // avoid segmentation fault in case users give empty values
    if (str(len) > 0)
    {
            t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}