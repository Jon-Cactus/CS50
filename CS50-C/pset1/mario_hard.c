#include <cs50.h>
#include <stdio.h>

void print_row(int air, int bricks, int decline);

int main(void)
{
    // make sure that the user's input is greater than 1
    int height;
    do
    {
        height = get_int("Size: ");
    }
    while (height < 1 || height > 8);

    // initial loop
    for (int i = 0; i < height; i++)
    {
        // inner loop being called through a function
        print_row(height - i - 1, i + 1, i + 1);
    }
}

void print_row(int air, int bricks, int decline)
{
    // makes air spaces
    for (int i = air; i > 0; i--)
    {
        printf(" ");
    }

    // makes blocks
    for (int j = 0; j < bricks; j++)
    {
        printf("#");
    }
    // Space inbetween
    printf("  ");
    {
        // descending stairs
        for (int k = 0; k < decline; k++)
        {
            printf("#");
        }
    }
    printf("\n");
}

