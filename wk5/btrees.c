#include <stdio.h>
#include <stdlib.h>

// implement single linked lists
typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

int main(int argc, char *argv[])
{
    node *list = NULL;
}

// Search for a value in a binary tree using recursion
// Downside: memory consumption (a lot more)
// Upside:
bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    if (number < tree->number)
    {
        return search(tree->left, number);
    }
    else if (number > tree->number)
    {
        return search(tree->right, number);
    }
    else
    {
        return true;
    }
}