#include <stdio.h>

// try to print a 3-block barrier in mario.
int main(void)
{
    // this introduces a logical bug => actually prints a 4-block barrier
    for (int i = 0; i <=3; i++)
    {
        // use printf to debug, but this should not be included in the final program.
        printf("i is %i\n", i);
        printf("#\n");
    }
}

