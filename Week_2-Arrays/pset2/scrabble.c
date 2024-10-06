#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// create an array which acts like a map by making a=0, b=1, c=2 etc. to give them their index

// Check each character for its score
int get_score(string s) {
    const static int points[] = {
        1,  // A
        3,  // B
        3,  // C
        2,  // D
        1,  // E
        4,  // F
        2,  // G
        4,  // H
        1,  // I
        8,  // J
        5,  // K
        1,  // L
        3,  // M
        1,  // N
        1,  // O
        3,  // P
        10, // Q
        1,  // R
        1,  // S
        1,  // T
        1,  // U
        4,  // V
        4,  // W
        8,  // X
        4,  // Y
        10  // Z
    };

    int total = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        int index = toupper(s[i]) - 'A';
        int score = points[index];
        total += score;
    }
    return total;
}

int main(void) {

    // prompt player 1 and 2 for their words

    string word1 = get_string("Player 1: \n");
    string word2 = get_string("Player 2: \n");

    // check points
    int p1points = get_score(word1);
    int p2points = get_score(word2);

    printf("Player 1: %i points!\nPlayer 2: %i points!\n", p1points, p2points);

    if (p1points > p2points) {
        printf("player 1 wins by %i points!\n", p1points - p2points);
    } else if (p2points > p1points) {
        printf("player 2 wins by %i points!\n", p2points - p1points);
    } else {
        printf("Tie!");
    }
}