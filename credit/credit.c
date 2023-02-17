#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string get_card(void);
void process(string card_num);
int main(void)
{
    process("233459-8723");
}

void process(string card_num)
{
    char *str = card_num;
    size_t length = strlen(str);

    for (size_t i = 0; i < length; i++)
    {
        if (isdigit(str[i]) == true)
        {
            printf("%c\n", str[i]);
        }

    }
}

string get_card(void)
{
    string card_num = get_string("Input your card number: ");
    return card_num;
}