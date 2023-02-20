#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

long get_card(void);
int count_digit(long card_num);
void validate(long card_num);
int main(void)
{
    get_card();
}

void validate(long card_num)
{
    int length = count_digit(card_num);
    // AMEX
    if (length == 15)
    {
        int first_two = card_num / 10000000000000;
        if (first_two == 34 || first_two == 37)
        {
            printf("AMEX\n");
        }
    }
    // MASTER
    else if (length == 16)
    {
        int first_two = card_num / 100000000000000;
        if (first_two >= 51 && first_two <= 55)
        {
            printf("MASTER\n");
        }
        else if (first_two / 10 == 4)
        {
            printf("VISA\n");
        }
    }
    // VISA
    else if (length == 13)
    {
        int first_one = card_num / 1000000000000;
        if (first_one == 4)
        {
            printf("MASTER\n");
        }
        else if (first_two / 10 == 4)
        {
            printf("VISA\n");
        }
    }
}

int count_digit(long card_num)
{
    int count = 0;
    do
    {
    n /= 10;
    ++count;
    }
    while (n != 0);
    return count;
}

long get_card(void)
{
    long card_num = get_long("Input your card number: ");
    printf("%li\n", card_num);
    string val = validate(card_num);
    return val;
}