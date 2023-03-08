// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char *tmp_word = NULL;
    while (fscanf(file, "%s", tmp_word) != EOF)
    {
        node *n = malloc(sizeof(node));
        // Catch in case the memory is not enough
        if (n == NULL)
        {
            return 1;
        }
        n->word = tmp_word;
        add_to_table(n);
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}


// Add the node to hash table
 bool add_to_table(node *n)
 {
    if (table[hash(n->word)] != NULL)
    {
        table[hash(n->word)] = n->word;
        n->next = NULL;
        return 1;
    }
    else if (table[hash(n->word)].next != NULL)
    {

    }
 }