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
    printf("block size: %i\n", block_size);

    // Write reversed audio to file
    long now = ftell(file); // 44
    long now1 = ftell(out); // 44

    fseek(file, 0, SEEK_END);
    int size = ftell(file); // Total size: 352844
    int no_blocks = (size - 44) / block_size; // 88200
    printf("no of blocks: %i\n", no_blocks);

    for (int i = 0; i < no_blocks; i++)
    {
        uint8_t block[block_size];
        fseek(file, -1 * block_size, SEEK_CUR); // seek backward 1 from current position
        fread(block, block_size, 1, file);
        fwrite(block, block_size, 1, out);
        fseek(file, -2 * block_size, SEEK_CUR);
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
    return header.numChannels * (header.bitsPerSample) / 8;
}