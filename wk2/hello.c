#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? \n");
    printf("hello, %s\n", name);
}


// to use 3rd party library like cs50.h
// it has to be installed under /usr/include/...
// make is not a compiler, it uses "clang"
// the command line would be: "clang -lcs50 -o hello hello.c"
// "-lcs50 links the cs50 library and include the library"

// 4 steps that compiler does:
// 1. preprocess (i.e. include necessary libraries) ->
// 2. compile (from C to Assembly code) =>
// assembly code is what our intel or arm cpu actually understands
// 3. assemble (convert from assembly to machine code) =>
// 4. link (linking the machine codes from hello.c, stdio.h, cs50.h)


// .c file: your application
// .h file: a library that can be reused 