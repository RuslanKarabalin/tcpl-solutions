#include "stdio.h"
#include "stdlib.h"

// Exercise: Revise the main routine of the
// longest-line program so it will correctly
// print the length of arbitrarily long input lines,
// and as much as possible of the text

int getline(char **pline) {
    int size = 10;
    char *line = (char*) malloc(size);
    if (!line) return -1;

    int c, len = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (len + 1 >= size) {
            size *= 2;
            char *tmp = (char*) realloc(line, size);
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

int main() {
    int len;
    int max = 0;
    char *line = NULL;
    char *longest = NULL;

    while ((len = getline(&line)) > 0) {
        if (len > max) {
            free(longest);
            longest = line;
            max = len;
            line = NULL;
        } else {
            free(line);
        }
    }
    if (max > 0) {
        printf("%s\n", longest);
    }
    return 0;
}
