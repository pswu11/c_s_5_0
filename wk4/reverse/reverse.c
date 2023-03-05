#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("File %s not found.\n", infile);
        return 4;
    }

    // Read headerm from file
    WAVHEADER bf;
    fread(&bf, sizeof(WAVHEADER), 1, file);

    // Use check_format to ensure WAV format
    if (!check_format(bf))
    {
        printf("Unsupported file format.\n");
        return 4;
    }

    // Open output file for writing
    FILE *out = fopen(outfile, "w");
    if (out == NULL)
    {
        printf("File %s not found.\n", outfile);
        return 4;
    }

    // Write header to file
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outfile);

    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8
}

int check_format(WAVHEADER header)
{

    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        printf("Yes\n");
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}