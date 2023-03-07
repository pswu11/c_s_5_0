#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        // convert string to int
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        n->next = list;
        list = n;
    }

    // declare a temp node that will point to a node in the list
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next; // borrow the next of the current node and follow through
    }
}