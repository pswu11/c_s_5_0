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
    string result;
    for (int i = 0; i < strlen(txt); i++)
    {
        if (isupper(txt[i]))
        {
            result = strcat(result, sub[txt[i] - 'A']);
        }
        else if (islower(txt[i]))
        {
            result = strcat(result, sub[txt[i] - 'a']);
        }
    }
    return result;
}