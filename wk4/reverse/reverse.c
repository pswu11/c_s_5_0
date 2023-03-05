#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        return 1;
    }

    // Remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // Open input file for reading
    FILE *file = fopen(infile, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 4;
    }

    // Read headerm from file
    WAVHEADER bf;
    fread(&bf, sizeof(WAVHEADER), 1, file);

    // Use check_format to ensure WAV format
    if (bf[])

    // Open output file for writing
    // TODO #5

    // Write header to file
    // TODO #6

    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8
}

int check_format(WAVHEADER header)
{
    // TODO #4
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}