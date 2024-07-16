#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // make sure a valid integer is requested
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    int coins = 0;
    while (change > 0)
    {
        if (change >= 25)
        {
            change -= 25;
            coins++;
        }
        else if (change >= 10)
        {
            change -= 10;
            coins++;
        }
        else if (change >= 5)
        {
            change -= 5;
            coins++;
        }
        else
        {
            change -= 1;
            coins++;
        }
    }
    printf("%i\n", coins);
}
