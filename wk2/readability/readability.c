#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int calculate_index(string t);
int count_letters(string t);
int count_words(string t);
int count_sentences(string t);

int main(void)
{
    string t = get_string("Text input:");
    printf("index: %i", calculate_index(t));
}

// index = 0.0588 * L - 0.296 * S - 15.8
// no. of word = number of space in a text + 1 ==> every 100 words => / 100
// L is the average number of letters per 100 words in the text, and
// S is the average number of sentences per 100 words in the text.

int calculate_index(string t)
{
    int L = count_letters(t) / (float) count_words(t) * 100;
    int S = count_sentences(t) / (float) count_words(t) * 100;
    printf("L: %i \n S: %i", L, S);
    return 0.0588 * L - 0.296 * S - 15.8;
}

int count_letters(string t)
{
    int count = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        if (isalpha(t[i]))
        {
            count += 1;
        }
    }
    printf("Letters: %i\n", count);
    return count;
}

int count_words(string t)
{
    int count = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        if (isspace(t[i]))
        {
            count += 1;
        }
    }
    printf("Words: %i\n", count);
    return count + 1;
}

int count_sentences(string t)
{
    int count = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        if (strcmp(t[i], ".") || strcmp(t[i], "!") || strcmp(t[i], "?"))
        {
            count += 1;
        }
    }
    printf("Sentences: %i\n", count);
    return count + 1;
}