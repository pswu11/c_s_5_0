#include <cs50.h>
#include <stdio.h>

int get_start_size(void);
int get_end_size(int s);
float cal_years_required(int start, int end);

int main(void)
{
    // TODO: Prompt for start size
    int start = get_start_size();
    // TODO: Prompt for end size
    int end = get_end_size(start);
    // TODO: Calculate number of years until we reach threshold
    int years = cal_years_required(start, end);
    // TODO: Print number of years
    printf("Years: %i\n", years);
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

int cal_years_required(int start, int end)
{
    int year_end = start;
    year_count = 0;
    do
    {
        year_end += year_end / 3 - year_end / 4;
        year_count++;
    }
    while (year_end < end);
}