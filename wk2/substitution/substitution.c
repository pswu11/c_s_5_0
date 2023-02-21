#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validate_key(string key);
string convert(string txt, string sub);

int main(int argc, string argv[])
{
    string sub = argv[1];
    string input;
    do
    {
        input = get_string("plaintext: ");
    }
    while (!validate_key(sub));
    printf("Cipher: %s\n", convert(input, sub));
}

string convert(string txt, string sub)
{
    string s;
    char result[26];
    for (int i = 0; i < strlen(txt); i++)
    {
        if(!isalpha(txt[i]))
        {
            result[i] = txt[i];
            printf("%i: %c\n", i, txt[i]);
        }
        else
        {
            if (isupper(txt[i]))
            {
                result[i] = sub[txt[i] - 'A'];
                printf("%i: %c\n", i, txt[i]);
            }
            else if (islower(txt[i]))
            {
                result[i] = sub[txt[i] - 'a'];
                printf("%i: %c\n", i, txt[i]);
            }
        }
    }
    s = result;
    return s;
}

bool validate_key(string key)
{
    if (strlen(key) == 26)
    {
        for (int i = 0; i < strlen(key); i++)
        {
            if (key[i])

            for (int j = i + 1; j < strlen(key); j++)
            {
                if (key[i] == key[j])
                {
                    printf("Key must contain 26 characters.\n");
                    return false;
                }
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