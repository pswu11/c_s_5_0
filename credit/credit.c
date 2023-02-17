#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string get_card(void);
string process(string card_num);
int main(void)
{
    string processed_card_num = process(get_card());
    printf("%s", processed_card_num);
}

string process(string card_num)
{
    string processed = "";
    char card_array[] = card_num;
    for (int i = 0; i < strlen(card_num); i++)
    {
        strcat(processed, card_array[i]);
        printf("%s", processed);
    }
    return processed;
}

string get_card(void)
{
    string card_num = get_string("Input your card number: ");
    return card_num;
}