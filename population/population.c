#include <cs50.h>
#include <stdio.h>

int get_start_size(void);
int get_end_size(void);
int yearly_change(int size);
int main(void)
{
    // TODO: Prompt for start size
    start = get_start_size()
    // TODO: Prompt for end size
    end = get_end_size(s)
    // TODO: Calculate number of years until we reach threshold
    yearly_change
    // TODO: Print number of years
}

int get_start_size(void)
{
    int start_size;
    do
    {
        start_size = get_input("Start size:\n")
    }
    while (start_size <= 0);
    printf("Start size: %i\n", start_size);
    return start_size;
}

int get_end_size(int s)
{
    int end_size;
    do
    {
        end_size = get_input("End size:\n")
    }
    while (end_size <= get_start_size(s));
    printf("End size: %i\n", end_size);
    return end_size;
}

int yearly_change(int start)
{
    return start / 3 - start / 4;
}

float years_required(int start, int end)
{
    int year_end = start;
    do
    {
        yearly_change
    }
}