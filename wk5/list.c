#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // method # 1
    int list[3];

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", i);
    }

    // what if I want to increase the length of array without copying
    // the whole array to somewhere else for the extra slot?

    // method # 2
    int *list2 = malloc(3 * sizeof(int));
    // check in case out of memory
    if (list2 == NULL)
    {
        return 1;
    }
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", i);
    }
}