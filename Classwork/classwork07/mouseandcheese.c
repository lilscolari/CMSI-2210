#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_GUESSES 10

void printWordState(const char word[], char guessedLetters[], int length);
int isWordGuessed(char guessedLetters[], int length);

int main() {
    const char *wordList[10] = {
        "apple", "super", "grape", "might", "melon", "scare", "stair", "brace", "lover", "crane"
    };
    const char *word = wordList[rand() % 10];
    int wordLength = strlen(word);
    
    char guessedLetters[wordLength];
    for (int i = 0; i < wordLength; i++) {
        guessedLetters[i] = '_';
    }

    int incorrectGuesses = 0;
    char guess;
    int gameOver = 0;

    printf("Welcome to Mouse and Cheese!\n");
    printf("You have %d guesses to guess the word before the mouse reaches the cheese.\n", MAX_GUESSES);

    while (incorrectGuesses < MAX_GUESSES && !gameOver) {
        printWordState(word, guessedLetters, wordLength);
        printf("You have %d guesses left.\n", MAX_GUESSES - incorrectGuesses);
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        int correctGuess = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == tolower(guess)) {
                guessedLetters[i] = tolower(guess);
                correctGuess = 1;
            }
        }
        if (correctGuess) {
            printf("Good guess!\n");
        } else {
            incorrectGuesses++;
            printf("Incorrect guess!\n");
        }
        gameOver = isWordGuessed(guessedLetters, wordLength);
    }
    if (gameOver) {
        printf("Congratulations! You've guessed the word: %s\n", word);
    } else {
        printf("The mouse reached the cheese! The word was: %s\n", word);
    }
    return 0;
}

void printWordState(const char word[], char guessedLetters[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%c ", guessedLetters[i]);
    }
    printf("\n");
}

int isWordGuessed(char guessedLetters[], int length) {
    for (int i = 0; i < length; i++) {
        if (guessedLetters[i] == '_') {
            return 0;
        }
    }
    return 1;
}
