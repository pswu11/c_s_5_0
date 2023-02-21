#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string sub = argv[1];
    string input = get_string("plaintext: ");
}

string convert(string txt, string sub)
{
    char result[] = "";
    for (int i = 0; i < strlen(txt); i++)
    {
        if (isupper(txt[i]))
        {
            result[i] = sub[txt[i] - 'A'];
        }
        else if (islower(txt[i]))
        {
            result[i] = sub[txt[i] - 'a'];
        }
    }
    return string(result);
}

bool validate_key(string key)
{
    if (strlen(key) == 26)
    {
        for (int i = 0; i < strlen(key); i++)
        {
            for (int j = i + 1; j < strlen(key); j++)
            {
                if (tolower(key[i]) == tolower(key[j]))
                {
                    return false;
                }
            }
            if (!isalpha(key[i]))
            {
                return false;
            }
        }
    }
    else
    {
        return false
    }
}