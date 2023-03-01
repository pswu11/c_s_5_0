#include <stdio.h>

void swap (int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    swap(&x, &y);
}

void swap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// heap overflow: when you overflow the heap
// stack overflow: when you overflow the stack memory
// => they are specific incarnations of what are generally called buffer overflow