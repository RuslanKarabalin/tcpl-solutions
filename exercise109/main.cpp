#include "stdbool.h"
#include "stdio.h"

// Exercise: Write a program to copy its input to its output,
// replacing each string of one or more blanks by single blank
int main() {
    int c;
    bool lastWasSpace = true;
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            printf("%c", c);
            if (!lastWasSpace) {
                lastWasSpace = true;
            }
        } else {
            if (lastWasSpace) {
                lastWasSpace = false;
                printf("%c", c);
            }
        }
    }
    return 0;
}
