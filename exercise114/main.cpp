#include "limits.h"
#include "stdio.h"

#define ENG_ALPHABET_LENGTH 26

// Exercise: Write a program to print a histogram
// of the frequencies of different characters in its input
int main() {
    int c;
    int letters[ENG_ALPHABET_LENGTH];
    for (int i = 0; i < ENG_ALPHABET_LENGTH; ++i) {
        letters[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        if ('a' <= c && c <= 'z') {
            ++letters[c - 'a'];
        }
    }
    int maxLetterUsage = INT_MIN;
    for (int i = 0; i < ENG_ALPHABET_LENGTH; ++i) {
        if (letters[i] > maxLetterUsage) {
            maxLetterUsage = letters[i];
        }
    }
    for (int i = maxLetterUsage; i > 0; --i) {
        for (int j = 0; j < ENG_ALPHABET_LENGTH; ++j) {
            if (letters[j] >= i) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < ENG_ALPHABET_LENGTH; ++i) {
        printf("%c", 'a' + i);
    }
    printf("\n");
    return 0;
}
