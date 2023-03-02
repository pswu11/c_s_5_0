#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE pixel = image[0][0];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtBlue == 255 && image[i][j].rgbtGreen == 255 && image[i][j].rgbtRed == 255)
            {
                image[i][j].rgbtBlue = 115;
                image[i][j].rgbtGreen = 56;
                image[i][j].rgbtRed = 138;
            }
        }
    }
}
