#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int get_card(void);
void process(string card_num);
int main(void)
{
    get_card();
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
    int card_num = get_int("Input your card number: ");
    return card_num;
}