#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "word.c"

void hangman(int error) {
    switch (error) {
        case 0: printf("  +---+\n"
                   "  |   |\n"
                   "      |\n"
                   "      |\n"
                   "      |\n"
                   "      |\n"
                   "=========");break;
        case 1: printf("  +---+\n"
                       "  |   |\n"
                       "  O   |\n"
                       "      |\n"
                       "      |\n"
                       "      |\n"
                       "=========");break;
        case 2: printf("  +---+\n"
                       "  |   |\n"
                       "  O   |\n"
                       "  |   |\n"
                       "      |\n"
                       "      |\n"
                       "=========");break;
        case 3: printf("  +---+\n"
                       "  |   |\n"
                       "  O   |\n"
                       " /|   |\n"
                       "      |\n"
                       "      |\n"
                       "=========");break;
        case 4: printf("  +---+\n"
                       "  |   |\n"
                       "  O   |\n"
                       " /|\\  |\n"
                       "      |\n"
                       "      |\n"
                       "=========");break;
        case 5: printf("  +---+\n"
                   "  |   |\n"
                   "  O   |\n"
                   " /|\\  |\n"
                   " /    |\n"
                   "      |\n"
                   "=========");break;
        case 6: printf("  +---+\n"
                       "  |   |\n"
                       "  O   |\n"
                       " /|\\  |\n"
                       " / \\  |\n"
                       "      |\n"
                       "=========");break;
    }
}

int main() {
    srand(time(NULL));
    int random = rand() % 62;
    char selectedWord[12];
    int letterNumber = 0;
    printf("\nDevinez le mot :\n");
    for(letterNumber = 0; wordList[random][letterNumber]; letterNumber++) {
        selectedWord[letterNumber] = wordList[random][letterNumber];
    }

    char underscore[letterNumber];
    for(int j = 0; j < letterNumber;j++) {
        underscore[j] = '_';
    }

    char error = 0;
    char currentLetter;
    char wrongLetter[26];
    while(error < 6) {
        hangman(error);
        printf("\n");
        for(int j = 0; j < letterNumber; j++) printf("%c", underscore[j]);
        printf("\n");
        for(int j = 0; j < error; j++) printf("%c", wrongLetter[j]);
        printf("\n");

        scanf(" %c", &currentLetter);

        char flag = 0;
        int correctNumber = 0;
        for(int j = 0; j < letterNumber; j++) {
            if (currentLetter == selectedWord[j]) {
                underscore[j] = currentLetter;
                flag = 1;
            }
            if(underscore[j] == selectedWord[j]) correctNumber++;
        }
        if(flag == 0) {
            wrongLetter[error] = currentLetter;
            error++;
        }
        if(correctNumber == letterNumber) {
            printf("Bravo vous avez trouver le mot : ");
            for(int j = 0; j < letterNumber; j++) {
                printf("%c", underscore[j]);
            }
            return 0;
        }
    }
    hangman(6);
    printf("\nVous avez perdu, le mot était : ");
    for(int j = 0; j < letterNumber; j++) {
        printf("%c", selectedWord[j]);
    }
    return 1;
}
