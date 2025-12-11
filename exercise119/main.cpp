#include "stdio.h"
#include "stdlib.h"

int myGetLine(char **pline) {
    int size = 10;
    char *line = (char *)malloc(size);
    if (!line) return -1;

    int c, len = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (len + 1 >= size) {
            size *= 2;
            char *tmp = (char *)realloc(line, size);
            if (!tmp) {
                free(line);
                return -1;
            }
            line = tmp;
        }
        line[len++] = c;
    }
    if (len == 0 && c == EOF) {
        free(line);
        return 0;
    }
    line[len] = '\0';
    *pline = line;
    return len;
}

void reverse(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    for (int i = 0; i < len / 2; ++i) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

// Exercise: Write a function reverse(s) that
// reverses the character string s.
// Use it to write a program that
// reverses its input a line at a time.
int main() {
    int len;
    char *line = NULL;

    while ((len = myGetLine(&line)) > 0) {
        reverse(line);
        printf("%s\n", line);
    }
    return 0;
}
