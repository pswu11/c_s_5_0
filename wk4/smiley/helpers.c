#include "helpers.h"
#include "stdio.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            if (pixel.rgbtBlue == 255 && pixel.rgbtGreen == 255 && pixel.rgbtRed == 255)
            {
                pixel.rgbtBlue = 115;
                pixel.rgbtGreen = 56;
                pixel.rgbtRed = 138;
            }
            else
            {
                printf("no black found.\n");
            }
        }
    }
}
