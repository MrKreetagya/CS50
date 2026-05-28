#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int spaces = 0;
    int length = 0;
    int sen = 0;

    string sentence = get_string("Text: ");

    for (int i = 0, n = strlen(sentence); i < n; i++)
    {
        if (sentence[i] == ' ')
        {
            spaces = spaces + 1;
        }

        if (sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!')
        {
            sen = sen + 1;
        }

        if (isalpha(sentence[i]))
        {
            length = length + 1;
        }
    }

    int words = spaces + 1;

    float L = ((float) length / words) * 100;

    float S = ((float) sen / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
