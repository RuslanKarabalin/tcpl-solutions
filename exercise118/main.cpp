#include "stdio.h"
#include "stdlib.h"

int getline(char **pline) {
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

// Exercise: Write a program to remove trailing blanks
// and tabs from each line of input,
// and to delete entirely blank lines
int main() {
    int len;
    char *line = NULL;

    while ((len = getline(&line)) > 0) {
        int lastChar = -1;
        for (int i = len - 1; i > 0; --i) {
            char c = line[i];
            if (c == ' ' || c == '\t') {
                continue;
            } else {
                lastChar = i;
                break;
            }
        }
        ++lastChar;
        for (int i = 0; i < lastChar; ++i) {
            printf("%c", line[i]);
        }
        printf("\n");
    }
    return 0;
}
