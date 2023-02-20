#include <stdio.h>
#include <cs50.h>
#include <math.h>

const int size = 3;
float average(int numbers[], int length);

int main(void)
{
    // Introducing Arrays:
    // An arrary a data structure that stores your data back to back in the memory.
    // It's gonna be more memory efficient to store an array of 50 scores
    // than storing 50 integers separately.

    // Int in memory:
    // Each int declared uses 32 bits of memory.
    // Initializing an array of 3 integers.
    // int scores[3]; ==> 3 is the magic number, you should declare a variable if it's reused.
    int scores[size];
    // And you can use index to access/assign an value to the integer.
    // When there are repetitive codes, loop could help.
    for (int i = 0; i < size; i++)
    {
        scores[i] = get_int("Score: ");
    }

    int avg = average(scores, size);
    printf("Average: %i\n", avg);

    // Strings in memory:
    string sentence = "Hi!"; // String is basically an array of characters.
    // At the end of the string, there's a special "\0" or NUL
    // to represent end of the string in the memory.
}

float average(int numbers[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += numbers[i];
    }
    return sum / (float) length;
}


// WK2 Notes

// 3rd party Lib:
// To use 3rd party library like cs50.h
// it has to be installed under /usr/include/...
// make is not a compiler, it uses "clang"
// the command line would be: "clang -lcs50 -o hello hello.c"
// "-lcs50 links the cs50 library and include the library"

// .c file: your application
// .h file: a library that can be reused

// What a compiler does:
// 1. preprocess (i.e. include necessary libraries) ->
// 2. compile (from C to Assembly code) =>
// assembly code is what our intel or arm cpu actually understands
// 3. assemble (convert from assembly to machine code) =>
// 4. link (linking the machine codes from hello.c, stdio.h, cs50.h)


// Decompiling: reverse the process of compiling
// Is it possible? Yes, but not so obvious and it's not as easy as imagine.
// - variable names are not reversed
// - for loop and while loop might look different

// Debugging:
// 1. Logging: Use printf() to debug when it's a simple program. But it gets messy.
// 2. Debugger: Use breakpoints to trace the bugs, i.e. use debug50 for now
// 3. Rubber Duck: Talk to others, or a imaginary person like rubber duck.