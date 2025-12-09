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

// Exercise: Write a program to print all input
// lines that are longer than 80 characters
int main() {
    int len;
    char *line = NULL;

    while ((len = getline(&line)) > 0) {
        if (len > 80) {
            printf("%s\n", line);
            line = NULL;
        }
    }
    return 0;
}
