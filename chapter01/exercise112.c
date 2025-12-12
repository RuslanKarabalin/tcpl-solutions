#include "stdio.h"

#define IN 1
#define OUT 0

// Exercise: Write a program that prints its input
// one word per line
int main() {
    int state = OUT;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                printf("\n");
            }
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            printf("%c", c);
        } else if (state == IN) {
            printf("%c", c);
        }
    }
    return 0;
}
