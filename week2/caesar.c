#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int k = atoi(argv[1]);

    string plaintext = get_string("plaintext:  ");

    int len = strlen(plaintext);
    char ciphertext[len + 1];
    for (int i = 0; i < len; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]))
            {
                ciphertext[i] = ((plaintext[i] - 'a' + k) % 26) + 'a';
            }
            else if (isupper(plaintext[i]))
            {
                ciphertext[i] = ((plaintext[i] - 'A' + k) % 26) + 'A';
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[len] = '\0';

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
