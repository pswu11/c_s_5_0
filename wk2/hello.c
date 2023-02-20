#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? \n");
    printf("hello, %s\n", name);
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
// 2. Debugger: use breakpoints to trace the bugs