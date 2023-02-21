#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validate_key(string key);
void convert(string txt, string sub);

int main(int argc, string argv[])
{
    // Handle no argument or too many arguments.
    if (argc != 2)
    {
        return 1;
    }
    string sub = argv[1];
    // Handles when key is not valid.
    if (!validate_key(argv[1]))
    {
        return 1;
    }
    convert(get_string("plaintext: "), argv[1]);
}

// Covert the plain text into ciphertext with given arguments.
void convert(string txt, string sub)
{
    char result[strlen(txt)];
    printf("ciphertext: ");
    for (int i = 0; i < strlen(txt); i++)
    {
        // Return the original char when it is not alphabetic
        if (!isalpha(txt[i]))
        {
            result[i] = txt[i];
            printf("%c", result[i]);
        }
        else
        {
            // Handle the upper case character
            if (isupper(txt[i]))
            {
                result[i] = toupper(sub[txt[i] - 'A']);
                printf("%c", result[i]);
            }
            // Handle the lower case character
            else if (islower(txt[i]))
            {
                result[i] = tolower(sub[txt[i] - 'a']);
                printf("%c", result[i]);
            }
        }
    }
    printf("\n");
}

// Validate key
bool validate_key(string key)
{
    // Check if key contains 26 characters.
    if (strlen(key) == 26)
    {
        for (int i = 0; i < strlen(key); i++)
        {
            // Check if key contains non-alphabetic characters.
            if (isalpha(key[i]))
            {
                // Check if key contains repeated characters.
                for (int j = i + 1; j < strlen(key); j++)
                {
                    if (tolower(key[i]) == tolower(key[j]))
                    {
                        printf("Key must not contain repeated characters.\n");
                        return false;
                    }
                }
            }
            else
            {
                printf("Key must only contain alphabetic characters.\n");
                return false;
            }
        }
        return true;
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
}