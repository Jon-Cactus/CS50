#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float get_index(float words, float characters, float sentences)
{
    float L = (100 / words) * characters;
    float S = (100 / words) * sentences;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}

int main(void)
{
    string passage = get_string("Text: \n");
    float sentencecount = 0.0;
    float wordcount = 1.0;
    float charcount = 0.0;
    for (int i = 0; i < strlen(passage); i++)
    {
        if (passage[i] == ' ')
        {
            wordcount++;
        }
        else if (passage[i] == '!' || passage[i] == '?' || passage[i] == '.')
        {
            sentencecount++;
        }
        else if (isalpha(passage[i]))
        {
            charcount++;
        }
    }

    float index = get_index(wordcount, charcount, sentencecount) + 0.5;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)index);
    }
}