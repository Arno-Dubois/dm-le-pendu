#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "word.c"

void hangman(int error) {
    switch (error) {
        case 1: printf("  +---+\n"
                   "  |   |\n"
                   "      |\n"
                   "      |\n"
                   "      |\n"
                   "      |\n"
                   "=========");break;
        case 2: printf("  +---+\n"
                       "  |   |\n"
                       "  O   |\n"
                       "      |\n"
                       "      |\n"
                       "      |\n"
                       "=========");break;
        case 3: printf("  +---+\n"
                       "  |   |\n"
                       "  O   |\n"
                       "  |   |\n"
                       "      |\n"
                       "      |\n"
                       "=========");break;
        case 4: printf("  +---+\n"
                       "  |   |\n"
                       "  O   |\n"
                       " /|   |\n"
                       "      |\n"
                       "      |\n"
                       "=========");break;
        case 5: printf("  +---+\n"
                       "  |   |\n"
                       "  O   |\n"
                       " /|\\  |\n"
                       "      |\n"
                       "      |\n"
                       "=========");break;
        case 6: printf("  +---+\n"
                   "  |   |\n"
                   "  O   |\n"
                   " /|\\  |\n"
                   " /    |\n"
                   "      |\n"
                   "=========");break;
        case 7: printf("  +---+\n"
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
    int letterNumber;
    printf("\nDevinez le mot :\n");
    for(letterNumber = 0; letterNumber < (sizeof(wordList[random]) / sizeof(wordList[random][0])); letterNumber++) {
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
        for(int j = 0; j < letterNumber; j++) printf("%c", underscore[j]);
        for(int j = 0; j < error; j++) printf("%c", wrongLetter[j]);

        scanf(" %c", &currentLetter);

        char flag = 0;
        for(int j = 0; j < letterNumber && flag == 0; j++) {
            if (currentLetter == selectedWord[j]) {
                underscore[j] = currentLetter;
                flag = 1;
            }
        }
        if(flag == 0) {
            wrongLetter[error] = currentLetter;
            error++;
        }


    }


    //printf("Hello, World! %c\n", selectedWord[random]);
    return 0;
}
