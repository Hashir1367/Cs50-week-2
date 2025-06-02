#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Scrabble letter values
int POINTS[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
    5, 1, 3, 1, 1, 3,10, 1, 1, 1,
    1, 4, 4, 8, 4,10
};

// Function prototype
int compute_score(const char *word);

int main(void)
{
    char word1[100];
    char word2[100];

    // Prompt for Player 1 word
    printf("Player 1: ");
    scanf("%s", word1);

    // Prompt for Player 2 word
    printf("Player 2: ");
    scanf("%s", word2);

    // Compute scores
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

// Compute score of a word
int compute_score(const char *word)
{
    int score = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            int index = toupper(word[i]) - 'A';
            score += POINTS[index];
        }
    }

    return score;
}
