#include "stdbool.h"
#include "stdio.h"

// Exercise: Write a program to count
// blanks, tabs, and newlines
int main() {
    int c;
    int bc = 0;
    int tc = 0;
    int nc = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++bc;
        } else if (c == '\t') {
            ++tc;
        } else if (c == '\n') {
            ++nc;
        }
    }
    printf("Blanks count: %d\n", bc);
    printf("Tabs count: %d\n", tc);
    printf("Newlines count: %d\n", nc);
    return 0;
}
