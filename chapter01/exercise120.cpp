#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int myGetLine(char** pline) {
    int size = 10;
    char* line = (char*)malloc(size);
    if (!line) return -1;

    int c, len = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (len + 1 >= size) {
            size *= 2;
            char* tmp = (char*)realloc(line, size);
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

char* detab(char* str, int strLen, int tabSize) {
    assert(strLen > 0);
    assert(tabSize > 0);
    int size = strLen;
    char* newStr = (char*)malloc(size);
    int j = 0;
    int i = 0;
    char c = str[i];
    while (c != '\0') {
        if (c == '\t') {
            int spacesToAdd = tabSize - (j % tabSize);
            for (int t = 0; t < spacesToAdd; ++t) {
                if (j + 1 >= size) {
                    size *= 2;
                    char* tmp = (char*)realloc(newStr, size);
                    if (!tmp) {
                        free(newStr);
                        return NULL;
                    }
                    newStr = tmp;
                }
                newStr[j++] = ' ';
            }
        } else {
            if (j + 1 >= size) {
                size *= 2;
                char* tmp = (char*)realloc(newStr, size);
                if (!tmp) {
                    free(newStr);
                    return NULL;
                }
                newStr = tmp;
            }
            newStr[j++] = c;
        }
        c = str[++i];
    }
    newStr[j] = '\0';
    return newStr;
}

// Exercise: Write a program detab
// that replaces tabs in the input
// with the proper number of blanks
// to space to the next tab stop.
// Assume a fixed set of tab stops,
// say every n columns.
// Should n be a variable
// for a symbolic parameter?
int main() {
    int len;
    char* line = NULL;
    while ((len = myGetLine(&line)) > 0) {
        char* newLine = detab(line, len + 1, 4);
        printf("%s\n", newLine);
        free(line);
        free(newLine);
    }
    return 0;
}
