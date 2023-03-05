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
    long now = ftell(file); // 44
    long now1 = ftell(out);
    printf("Out: %li\n", now1);

    fseek(file, 0, SEEK_END); // Total size: 352844
    long size = ftell(file);

    fseek(file, -1, SEEK_CUR); // seek backward 1 from current position
    long neg = ftell(file);

    fseek(file, 44, SEEK_SET); // seek the start with +44 offset
    long neg1 = ftell(file);

    for (int i = 0; i < size - 44; i++)
    {
        fread(&buffer, 1, 1, file);
        fwrite(&buffer, 1, 1, out);
        fseek(file, -2, SEEK_CUR); // seek backward 1 from current position
    }
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