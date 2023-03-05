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
    fwrite(&bf, sizeof(WAVHEADER), 1, out);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(bf);

    // Write reversed audio to file
    long now = ftell(file);
    fseek(file, 5, SEEK_END);
    printf("%li\n", now); // 44
    long offset = ftell(file);
    printf("%li\n", offset); // end (total length)
    rewind(file);
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    printf("%li\n", size);
    rewind(file);
    fseek(file, -3, SEEK_END);
    long neg = ftell(file);
    printf("%li\n", neg);

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
    return header.numChannels * (header.bitsPerSample / 4);
}