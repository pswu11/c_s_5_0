#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int count_letters(string t);
int count_words(string t);
int count_sentences(string t);

int main(void)
{
    // Get text from user input and return
    // the numbers of letters, words, and sentences
    string t = get_string("Text:");
    int letter_count = count_letters(t);
    int word_count = count_words(t);
    int sentence_count = count_sentences(t);
    printf("Letters: %i\n", letter_count);
    printf("Words: %i\n", word_count);
    printf("Sentences: %i\n", sentence_count);

    // Calcuate the Coleman-Liau index
    float L = letter_count / (float) word_count * 100;
    float S = sentence_count / (float) word_count * 100;
    printf("L: %f \nS: %f \n", L, S);
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    // Set conditions for before grade 1 and above 16
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

// Count the number of letters
int count_letters(string t)
{
    int count = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        // Check if the char is alphabetical
        if (isalpha(t[i]))
        {
            count += 1;
        }
    }
    return count;
}

// Count the number of words
int count_words(string t)
{
    int count = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        // Count the number of spaces to determin the number of words
        if (isspace(t[i]))
        {
            count += 1;
        }
    }
    return count + 1;
}

// Count the number of sentences
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
    return count;
}