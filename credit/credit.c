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
        if (isdigit(str[i]) == true) // this needs to be rewrite.
        {
            printf("%c\n", str[i]);
        }

    }
}

int get_card(void)
{
    int card_num;

    do
    {
        card_num = get_int("Input your card number: ")
    }
    while
    {
        !isint(card_num);
    }

    return card_num;
}