#include "helpers.h"
#include "stdio.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    printf("height: %i, width: %i\n", height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            if (pixel.rgbtBlue == 255 && pixel.rgbtGreen == 255 && pixel.rgbtRed == 255)
            {
                image[i][j].rgbtBlue = 115;
                image[i][j].rgbtGreen = 56;
                image[i][j].rgbtRed = 138;
            }
        }
    }
}
