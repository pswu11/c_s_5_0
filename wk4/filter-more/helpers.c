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
    // Make a copy of existing image
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
            RGBTRIPLE *pixel = &image[i][j];
            // Calculate each pixel's 3x3 average
            float sum_red = 0, sum_green = 0,sum_blue = 0;
            int counter = 0;
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    int x = i + a;
                    int y = j + b;
                    // Ignore when the pixel doesn't exist
                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        sum_red += temp[x][y].rgbtRed;
                        sum_green += temp[x][y].rgbtGreen;
                        sum_blue += temp[x][y].rgbtBlue;
                        counter++;
                    }
                }
            }
            pixel->rgbtRed = round(sum_red / counter);
            pixel->rgbtGreen = round(sum_green / counter);
            pixel->rgbtBlue = round(sum_blue / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Make a copy of existing image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    // Create Sobel arrays to compute weighted sums Gx, Gy
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *pixel = &image[i][j];
            float gx_red = 0, gx_green = 0, gx_blue = 0;
            float gy_red = 0, gy_green = 0, gy_blue = 0;
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    if (i + a >=0 && i + a < height && j + b >= 0 && j + b < width)
                    {
                        // Calculate Gx, Gy
                        gx_red += temp[i + a][j + b].rgbtRed * Gx[a + 1][b + 1];
                        gx_green += temp[i + a][j + b].rgbtGreen * Gx[a + 1][b + 1];
                        gx_blue += temp[i + a][j + b].rgbtBlue * Gx[a + 1][b + 1];
                        gy_red += temp[i + a][j + b].rgbtRed * Gy[a + 1][b + 1];
                        gy_green += temp[i + a][j + b].rgbtGreen * Gy[a + 1][b + 1];
                        gy_blue += temp[i + a][j + b].rgbtBlue * Gy[a + 1][b + 1];

                        // Apply Sobel algorithm
                        int red = round(sqrt(pow(gx_red, 2) + pow(gy_red, 2)));
                        int green = round((float) sqrt(pow(gx_green, 2) + pow(gy_green, 2)));
                        int blue = round((float) sqrt(pow(gx_blue, 2) + pow(gy_blue, 2)));

                        // Cap the values at 255
                        if (red >= 255)
                        {
                            red = 255;
                        }
                        if (green >= 255)
                        {
                            green = 255;
                        }
                        if (blue >= 255)
                        {
                            blue = 255;
                        }
                        // Apply new values to the pixel
                        pixel->rgbtRed = red;
                        pixel->rgbtGreen = green;
                        pixel->rgbtBlue = blue;
                    }
                }
            }
        }
    }

    return;
}


