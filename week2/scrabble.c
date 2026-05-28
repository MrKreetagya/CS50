#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                       'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int value[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    string player1 = get_string("Enter your word player 1: ");
    string player2 = get_string("Enter your word player 2: ");
    int total1 = 0;
    int total2 = 0;
    for (int i = 0, n = strlen(player1); i < n; i++)
    {
        char current_letter = tolower(player1[i]);
        for (int j = 0; j < 26; j++)
        {
            if (current_letter == alphabet[j])
            {
                total1 = total1 + value[j];
            }
        }
    }
    for (int i = 0, n = strlen(player2); i < n; i++)
    {
        char current_letter = tolower(player2[i]);
        for (int m = 0; m < 26; m++)
        {
            if (current_letter == alphabet[m])
            {
                total2 = total2 + value[m];
            }
        }
    }
    if (total1 == total2)
    {
        printf("Tie!\n");
    }
    if (total1 > total2)
    {
        printf("Player 1 Wins!\n");
    }
    if (total1 < total2)
    {
        printf("Player 2 Wins!\n");
    }
}
