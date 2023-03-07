#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // method # 1
    int list[3];

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // method # 2
    int *list2 = malloc(3 * sizeof(int));
    // check in case out of memory
    if (list2 == NULL)
    {
        return 1;
    }
    list2[0] = 1;
    list2[1] = 2;
    list2[2] = 3;

    // what if I want to increase the length of array without copying
    // the whole array to somewhere else for the extra slot?

    // int *tmp = malloc(4 * sizeof(int));
    int *tmp = realloc(list2, 4 * sizeof(int));
    if (list2 == NULL)
    {
        free(list2);
        return 1;
    }
    tmp[3] = 4;
    list2 = tmp;
    // list was a pointer, now it's pointing to tmp pointer
    // that points to the new chunk of memory
    // basically two variables point to the same memory address
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list2[i]);
    }
    return 0;

    // method # 3
    // what if I want to increase the length of array without copying
    // the whole array to somewhere else for the extra slot?


}