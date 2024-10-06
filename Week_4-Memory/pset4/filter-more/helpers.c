// CODE THAT I WROTE

#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round(
              ((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed)
               / 3);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int leftHalfBlue;
    int leftHalfRed;
    int leftHalfGreen;
    int rightHalfBlue;
    int rightHalfRed;
    int rightHalfGreen;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++)
        {
            leftHalfBlue = image[i][j].rgbtBlue;
            leftHalfRed = image[i][j].rgbtRed;
            leftHalfGreen = image[i][j].rgbtGreen;

            rightHalfBlue = image[i][(width - 1) - j].rgbtBlue;
            rightHalfRed = image[i][(width - 1) - j].rgbtRed;
            rightHalfGreen = image[i][(width - 1) - j].rgbtGreen;

            image[i][(width - 1) - j].rgbtBlue = leftHalfBlue;
            image[i][(width - 1) - j].rgbtRed = leftHalfRed;
            image[i][(width - 1) - j].rgbtGreen = leftHalfGreen;

            image[i][j].rgbtBlue = rightHalfBlue;
            image[i][j].rgbtRed = rightHalfRed;
            image[i][j].rgbtGreen = rightHalfGreen;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avgRed = 0;
            int avgGreen = 0;
            int avgBlue = 0;
            int goodNeighbor = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k > -1 && k < height && l > -1 && l < width)
                    {
                        goodNeighbor++;
                        avgRed += tmp[k][l].rgbtRed;
                        avgGreen += tmp[k][l].rgbtGreen;
                        avgBlue += tmp[k][l].rgbtBlue;
                    }
                }
            }
            image[i][j].rgbtRed = round((float)avgRed / (float)goodNeighbor);
            image[i][j].rgbtGreen = round((float)avgGreen / (float)goodNeighbor);
            image[i][j].rgbtBlue = round((float)avgBlue / (float)goodNeighbor);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j] = image[i][j];
        }
    }
    int gxMultipliers[3][3] = {
        { -1, 0, 1 },
        { -2, 0, 2 },
        { -1, 0, 1 }
    };

    int gyMultipliers[3][3] = {
        { -1, -2, -1 },
        { 0, 0, 0 },
        { 1, 2, 1 }
    };

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //coordinates for gx and gy arrays
            int x;
            int y;

            //store multiplied values
            int gxRed = 0;
            int gyRed = 0;
            int gxGreen = 0;
            int gyGreen = 0;
            int gxBlue = 0;
            int gyBlue = 0;

            int newRed;
            int newGreen;
            int newBlue;
            x = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                printf("x = %i\n", x);
                y = 0;
                for (int l = j - 1; l <= j + 1; l++)
                {
                    printf("y = %i\n", y);
                    // Handle pixels outside the border of the picture
                    if (k < 0 || k >= height || l < 0 || l >= width)
                    {
                        y++;
                        continue;
                    }
                    else
                    {
                        gxRed += gxMultipliers[x][y] * tmp[k][l].rgbtRed;
                        gxGreen += gxMultipliers[x][y] * tmp[k][l].rgbtGreen;
                        gxBlue += gxMultipliers[x][y] * tmp[k][l].rgbtBlue;

                        gyRed += gyMultipliers[x][y] * tmp[k][l].rgbtRed;
                        gyGreen += gyMultipliers[x][y] * tmp[k][l].rgbtGreen;
                        gyBlue += gyMultipliers[x][y] * tmp[k][l].rgbtBlue;
                    }
                    y++;
                }
                x++;
            }
            newRed = round(sqrt(((float)gxRed * (float)gxRed) + ((float)gyRed * (float)gyRed)));
            newGreen = round(sqrt(((float)gxGreen * (float)gxGreen) + ((float)gyGreen * (float)gyGreen)));
            newBlue = round(sqrt(((float)gxBlue * (float)gxBlue) + ((float)gyBlue * (float)gyBlue)));
            if (newRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = newRed;
            }
            if (newGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = newGreen;
            }
            if (newBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = newBlue;
            }
        }
    }
    return;
}