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

string validate(long card_num)
{

}

long get_card(void)
{
    long card_num = get_long("Input your card number: ");
    printf("%li\n", card_num);
    string val = validate(card_num);
    return val;
}