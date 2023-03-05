#include "helpers.h"
#include "math.h"

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
    RGBTRIPLE temp[height][width] = image[height][width];
    RGBTRIPLE *pixel = &image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate each pixel's 3x3 average
            for (int a = -1; a < 2; a++)
            {
                RGBTRIPLE sum[9];
                int count = 0;
                if (i + a >=0 && i + a < height)
                {
                    for (int b = -1; b < 2; b++)
                    {
                        if (j + b >=0 && j + b < width)
                        {
                            sum[count].rgbtBlue += temp[i][j].rgbtBlue;
                            sum[count].rgbtRed += temp[i][j].rgbtRed;
                            sum[count].rgbtGreen += temp[i][j].rgbtGreen;
                            count +=1;
                        }
                    }
                }
                pixel->rgbtBlue = sum.rgbtBlue / count;
                pixel->rgbtRed = sum.rgbtRed / count;
                pixel->rgbtGreen = sum.rgbtGreen / count;
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
