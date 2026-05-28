#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int heig, row, col, space;
    do
    {
        heig = get_int("enter the height: ");
    }
    while (heig < 1 || heig > 8);

    for (row = 0; row < heig; row++)

    {
        for (space = 0; space < heig - row - 1; space++)
        {
            printf(" ");
        }
        for (col = 0; col <= row; col++)
        {
            printf("#");
        }
        printf("\n");
    }
}
