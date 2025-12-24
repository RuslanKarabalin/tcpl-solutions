#include <stdio.h>

#define IN 1
#define OUT 0

// Exercise: How would you test the word count program?
// What kinds of input are most likely to uncover
// bugs if there are any?
//
// TESTS:
// abc 123\t4  q
// a\tb\t\tt 1
int main() {
    int state = OUT;
    int wc = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++wc;
        }
    }
    printf("Word count: %d\n", wc);
    return 0;
}
