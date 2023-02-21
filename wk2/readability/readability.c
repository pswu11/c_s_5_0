#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string t);
int count_words(string t);
int count_sentences(string t);

int main(void)
{
    string t = get_string("Text:");
    int letter_count = count_letters(t);
    int word_count = count_words(t);
    int sentence_count = count_sentences(t);
    printf("Letters: %i\n", letter_count);
    printf("Words: %i\n", word_count);
    printf("Sentences: %i\n", sentence_count);
    int L = letter_count / (float) word_count * 100;
    int S = sentence_count / (float) word_count * 100;
    printf("L: %i \nS: %i \n", L, S);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    printf("Score: %f", index);
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
    return count + 1;
}

int count_sentences(string t)
{
    int count = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        if (t[i] == '.' || t[i] == '!' || t[i] == '?')
        {
            count += 1;
        }
    }
    return count + 1;
}