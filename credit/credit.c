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
    long card = get_card();
    validate(card);
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
            printf("VISA\n");
        }
    }
    // INVALID
    else
    {
        printf("INVALID\n");
    }
}

bool checksum(long card_num)
{
    int length = count_digit(card_num);
    int val;
    for (int i = 1; i <= length; i++)
    {
        if (i % 2 == 0)
        {
            val += card_num[-i] * 2;
        }
    }
}

int count_digit(long card_num)
{
    int count = 0;
    long n = card_num;
    do
    {
    n /= 10;
    ++count;
    }
    while (n != 0);
    return count;
}

int convert_array(long card_num)
{
    
}

long get_card(void)
{
    long card_num = get_long("Input your card number: ");
    printf("%li\n", card_num);
    return card_num;
}