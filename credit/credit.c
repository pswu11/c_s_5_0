#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

long get_card(void);
void process(string card_num);
int main(void)
{
    get_card();
}

void validate(long card_num)
{
    int length = strlen(str(card_num));
    // AMEX
    if (length == 15)
    {
        int first_two = card_num / pow10l(long double 14);
        if (first_two == 34 || first_two == 37)
        {
            printf("AMEX\n");
        }
    }
    // MASTER
    if (length == 16)
    {
        int first_two = card_num / 10000000000000;
        if (first_two == 34 || first_two == 37)
        {
            printf("AMEX\n");
        }
    }
}

long get_card(void)
{
    long card_num = get_long("Input your card number: ");
    printf("%li\n", card_num);
    string val = validate(card_num);
    return val;
}