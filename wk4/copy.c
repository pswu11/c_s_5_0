#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");

    // Make a COPY #1

    char *t = s; // not the right way to make a copy of t
    // above line assigns t with memory address of s;
    // hence both t and s points to the same address.

    // avoid segmentation fault in case users give empty values
    if (strlen(t) > 0)
    {
            t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // Make a COPY #2 => not recommended cuz things could still go wrong.
    // i.e. get_string will return NULL if something goes wrong.
    // i.e. alloc will retrun NULL if it's asking too much memory.

    // add one more memory slot longer than s
    char *t2 = malloc(strlen(s) + 1);
    // correct way to make a copy of s
    // +1 for having space for \0

    // optimized for loops by making strlen(s) a varialbe so the loop doesn't
    // call the same function again and again.
    for (int i = 0, n = strlen(s) + 1; i < n; i++)
    {
        t2[i] = s[i];
    }

    if (strlen(t2) > 0)
    {
            t2[0] = toupper(t2[0]);
    }

    printf("s: %s\n", s);
    printf("t2: %s\n", t2);

    // it's a good habit to return the memory after it's used.
    free(t2);

    // Make a COPY #3

    strcpy(t3, s);

    if (strlen(t3) > 0)
    {
            t3[0] = toupper(t3[0]);
    }

    printf("s: %s\n", s);
    printf("t3: %s\n", t3);

}

// malloc: ask your OS to allocate free memory
// malloc could freeze your computer if the program has bug
// that over allocate the memory.
// free: free the memory after you're done with it