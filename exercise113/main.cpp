#include <climits>

#include "stdio.h"

#define IN 1
#define OUT 0

// Exercise: Write a program to print a histogram of the lengths of words in its
// input. It is easy to draw the histogram with the bars horizontal; a vertical
// is more challenging
int main() {
    int state = OUT;
    int c;
    int size = 10;
    int *wLengths = new int[size]();
    int wc = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                if (wc + 1 >= size) {
                    int newSize = 2 * size;
                    int *newArr = new int[newSize]();
                    for (int i = 0; i < size; ++i) {
                        newArr[i] = wLengths[i];
                    }
                    delete[] wLengths;
                    size = newSize;
                    wLengths = newArr;
                }
                ++wc;
            }
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++wLengths[wc];
        } else if (state == IN) {
            ++wLengths[wc];
        }
    }

    // HORIZONTAL
    printf("===HORIZONTAL===\n");
    for (int i = 0; i < wc; ++i) {
        for (int j = 0; j < wLengths[i]; ++j) {
            printf("-");
        }
        printf("\n");
    }

    // VERTICAL
    printf("====VERTICAL====\n");
    int maxWordLength = INT_MIN;
    for (int i = 0; i < wc; ++i) {
        if (wLengths[i] > maxWordLength) {
            maxWordLength = wLengths[i];
        }
    }
    for (int i = maxWordLength; i > 0; --i) {
        for (int j = 0; j < wc; ++j) {
            if (wLengths[j] >= i) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    delete [] wLengths;
    return 0;
}
