#include <stdio.h>
#include <stdlib.h>

typedef struct node
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
        int number = atoi(argv[i]); // ideally you need to do error checking

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL; // get rid of garbage

        n->next = list;
        list = n;
    }

    // declare a temp node that will point to a node in the list
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next; // follow through and point to the next node
    }

    // free the memory
    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr-> next;
        free(ptr);
        ptr = next;
    }
}