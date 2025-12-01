#include "stdbool.h"
#include "stdio.h"

// Exercise: Write a program to copy its input to its output,
// replacing each string of one or more blanks by single blank
int main() {
    int c;
    bool isFirst = true;
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            printf("%c", c);
            if (!isFirst) {
                isFirst = true;
            }
        } else {
            if (isFirst) {
                isFirst = false;
                printf("%c", c);
            }
        }
    }
    return 0;
}
