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
        printf("Usage: ./reverse input.wav output.wav\n");
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
        printf("Input is not a WAV file.\n");
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

    // Write reversed audio to file:
    // Get total size of audio data
    fseek(file, 0, SEEK_END);
    int size = ftell(file); // Total size: 352844
    // Seek 1 block backward from current position as stating point
    fseek(file, -1 * block_size, SEEK_END);

    for (int i = 0; i < (size - 44) / block_size; i++)
    {
        uint8_t block[block_size];
        fread(block, block_size, 1, file);
        fwrite(block, block_size, 1, out);
        fseek(file, -2 * block_size, SEEK_CUR);
    }
    fclose()
}

int check_format(WAVHEADER header)
{
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    return header.numChannels * (header.bitsPerSample) / 8;
}