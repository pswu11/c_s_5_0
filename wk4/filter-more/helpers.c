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
    // Iterate over each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate each pixel's 3x3 average
            RGBTRIPLE sum;
            sum.rgbtBlue = 0;
            sum.rgbtRed = 0;
            sum.rgbtGreen = 0;
            int count = 0;
            for (int a = -1; a < 2; a++)
            {
                if (i + a >=0 && i + a < height)
                {
                    for (int b = -1; b < 2; b++)
                    {
                        if (j + b >=0 && j + b < width)
                        {
                            sum.rgbtBlue += temp[i + a][j + b].rgbtBlue;
                            count +=1;
                        }
                    }
                }
            }
            printf("Sum: %i\n", sum.rgbtBlue);
            printf("Count: %i\n", count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}


