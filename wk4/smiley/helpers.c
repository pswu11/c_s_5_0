#include "helpers.h"
#include "stdio.h"

// color any black pixel to purple
void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Create a pointer to where the image array is at in the memory
            RGBTRIPLE *pixel = &image[i][j];
            // Color the pixel if the pixel is black (then a single color code can't be 0x00)
            if (pixel->rgbtRed != 0x00)
            {
                pixel->rgbtBlue = 230;
                pixel->rgbtGreen = 80;
                pixel->rgbtRed = 160;
            }
        }
    }
}
