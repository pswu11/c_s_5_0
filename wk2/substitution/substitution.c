#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validate_key(string key);

int main(int argc, string argv[])
{
    string sub = argv[1];
    string input = get_string("plaintext: ");
    bool b = validate_key(input);
    printf("%d", b);
}

string convert(string txt, string sub)
{
    char result[26];
    for (int i = 0; i < strlen(txt); i++)
    {
        if (isupper(txt[i]))
        {
            result[i] = sub[txt[i] - 'A'];
        }
        else if (islower(txt[i]))
        {
            printf("%i\n", sub[txt[i] - 'a']);
        }
    }
    return result;
}

bool validate_key(string key)
{
    if (strlen(key) == 26)
    {
        for (int i = 0; i < strlen(key); i++)
        {
            if (!isalpha(key[i]))
            {
                return false;
            }
            for (int j = i + 1; j < strlen(key); j++)
            {
                if (tolower(key[i]) == tolower(key[j]))
                {
                    return false;
                }
            }
            return true;
        }
    }
    else
    {
        return false
    }
}