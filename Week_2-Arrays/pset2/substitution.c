#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int check_key(string key)
{
    static int checker[26] = {0};
    for (int i = 0; i < strlen(key); i++)
    {
        char current_char = toupper(key[i]);
        int index = current_char - 'A';
        checker[index]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (checker[i] != 1)
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, string argv[])
{
    //check for key
    if (argc != 2)
    {
        printf("Usage: ./substitution key (26 unique characters)\n");
        return 1;
    }
    //checks if key has 26 unique characters
    else if (check_key(argv[1]) != 0)
    {
        printf("Input 26 unique characters in any order but without repeats!\n");
        return 1;
    }
    else
    {
        // change key chars to all uppercase
        string key = argv[1];
        char upper_key[strlen(key)];
        for (int i = 0; i < strlen(key); i++)
        {
            upper_key[i] = toupper(key[i]);
        }
        //turns plaintext into ciphertext
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plaintext); i++)
        {
            char ciphertext[strlen(plaintext)];
            char current_char = plaintext[i];
            if (isalpha(current_char))
            {
                int index;
                if (isupper(current_char))
                {
                    index = current_char - 'A';
                    ciphertext[i] = upper_key[index];
                }
                else if (islower(current_char))
                {
                    index = toupper(current_char) - 'A';
                    ciphertext[i] = tolower(upper_key[index]);
                }
            }
            else
            {
                ciphertext[i] = current_char;
            }
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
    return 0;
}