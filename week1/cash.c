#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int quarter = 0;
    int ten = 0;
    int five = 0;
    int one = 0;
    int change = get_int("Enter the amount of change: ");
    while (change != 0)
    {
        if (change >= 25)
        {
            change = change - 25;
            quarter = quarter + 1;
        }
        else if (change >= 10)
        {
            change = change - 10;
            ten = ten + 1;
        }
        else if (change >= 5)
        {
            change = change - 5;
            five = five + 1;
        }
        else
        {
            change = change - 1;
            one = one + 1;
        }
    }
    int total_coins = quarter + ten + five + one;
    printf("%i\n", total_coins);
}
