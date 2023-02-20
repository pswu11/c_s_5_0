#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

long get_card(void);
int count_digit(long card_num);
void validate(long card_num);
bool checksum(long card_num);

int main(void)
{
    long card_num = get_card();
    if (checksum(card_num) == true)
    {
        validate(card_num);
    }
    else
    {
        printf("INVALID\n");
    }
}

// validate credit card's provider
void validate(long card_num)
{
    int length = count_digit(card_num);
    // AMEX
    if (length == 15)
    {
        // get the first two digits of card number
        int first_two = card_num / 10000000000000;
        if (first_two == 34 || first_two == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // MASTER
    else if (length == 16)
    {
        // get the first two digits of card number
        int first_two = card_num / 100000000000000;
        if (first_two >= 51 && first_two <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (first_two / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // VISA
    else if (length == 13)
    {
        // get the first digit of card number
        int first_one = card_num / 1000000000000;
        if (first_one == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // INVALID
    else
    {
        printf("INVALID\n");
    }
}

// use luhn's algorithm to validate
bool checksum(long card_num)
{
    int length = count_digit(card_num);
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < length; i++)
    {
        int digit = 0;
        // step1. multiply every other digit by 2 starting from the second-to-last digit as sum1
        if (i % 2 == 1)
        {
            digit = card_num % 10 * 2;
            card_num = card_num / 10;
            if (digit / 10 == 0)
            {
                sum1 += digit;
            }
            else
            {
                sum1 += digit / 10 + digit % 10;
            }
        }
        // step2. add the sum of the digits that were not multiplied by 2 as sum2
        else
        {
            digit = card_num % 10;
            card_num = card_num / 10;
            sum2 += digit;
        }
    }
    // step3. get sum two values and check if the last digit equals to zero
    if ((sum1 + sum2) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// count the digits of credit card number
int count_digit(long card_num)
{
    int count = 0;
    long n = card_num;
    do
    {
        n /= 10;
        count++;
    }
    while (n != 0);
    return count;
}

// get input of credit card number
long get_card(void)
{
    long card_num = get_long("Input your card number: ");
    return card_num;
}