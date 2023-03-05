#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *pixel = &image[i][j];
            int avg = round((pixel->rgbtBlue + pixel->rgbtRed + pixel->rgbtGreen) / (float) 3);
            pixel->rgbtBlue = avg;
            pixel->rgbtRed = avg;
            pixel->rgbtGreen = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE temp[width];
        for (int j = 0; j < width; j++)
        {
            temp[j] = image[i][width - 1 - j];
        }
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *pixel = &image[i][j];
            pixel->rgbtBlue = temp[j].rgbtBlue;
            pixel->rgbtRed = temp[j].rgbtRed;
            pixel->rgbtGreen = temp[j].rgbtGreen;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE *pixel = &image[height][width];
    // Make a copy
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    printf("first pixel: (%i, %i, %i)\n", temp[0][0].rgbtRed, temp[0][0].rgbtGreen, temp[0][0].rgbtBlue);
    // Iterate over each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate each pixel's 3x3 average
            RGBTRIPLE sum;
            sum.rgbtRed = 0;
            sum.rgbtGreen = 0;
            sum.rgbtBlue = 0;
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    int x = i + a;
                    int y = j + b;
                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        sum.rgbtRed += temp[x][y].rgbtRed;
                        sum.rgbtGreen += temp[x][y].rgbtGreen;
                        sum.rgbtBlue += temp[x][y].rgbtBlue;
                    }
                }
            }
            pixel->rgbtRed = sum.rgbtRed / 9;
            pixel->rgbtGreen = sum.rgbtGreen / 9;
            pixel->rgbtBlue = sum.rgbtBlue / 9;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}


