#include "helpers.h"
#include "stdio.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    printf("height: %i, width: %i\n", height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // create a pointer to where the image array is at in the memory
            RGBTRIPLE *pixel = &image[i][j];
            if (pixel->rgbtBlue == 255)
            {
                pixel->rgbtBlue = 230;
                pixel->rgbtGreen = 80;
                pixel->rgbtRed = 160;
            }
        }
    }
}
