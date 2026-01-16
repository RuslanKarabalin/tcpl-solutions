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

char* entab(char* str, int strLen, int tabSize) {
    assert(strLen > 0);
    assert(tabSize > 0);
    int size = strLen;
    char* newStr = (char*)malloc(size);
    int j = 0;
    int i = 0;
    int column = 0;
    char c = str[i];
    while (c != '\0') {
        if (c == ' ') {
            int startCol = column;
            while (c == ' ') {
                column++;
                c = str[++i];
            }
            int endCol = column;

            while (((startCol / tabSize) + 1) * tabSize <= endCol) {
                if (j + 1 > size) {
                    size *= 2;
                    char* tmp = (char*)realloc(newStr, size);
                    if (!tmp) {
                        free(newStr);
                        return NULL;
                    }
                    newStr = tmp;
                }
                newStr[j++] = '\t';
                startCol = ((startCol / tabSize) + 1) * tabSize;
            }
            while (startCol < endCol) {
                if (j + 1 > size) {
                    size *= 2;
                    char* tmp = (char*)realloc(newStr, size);
                    if (!tmp) {
                        free(newStr);
                        return NULL;
                    }
                    newStr = tmp;
                }
                newStr[j++] = ' ';
                startCol++;
            }
        } else {
            if (j + 1 > size) {
                size *= 2;
                char* tmp = (char*)realloc(newStr, size);
                if (!tmp) {
                    free(newStr);
                    return NULL;
                }
                newStr = tmp;
            }
            newStr[j++] = c;
            column++;
            c = str[++i];
        }
    }
    newStr[j] = '\0';
    return newStr;
}

// Exercise: Write a porgram entab
// that replaces strings of blanks
// by the minimum number of tabs and
// blanks to achieve the same spacing.
// Use the same tab stops as for detab.
// When either a tab or a single blank
// would suffice to reach a tab stop,
// which should be given preference?
int main() {
    int len;
    char* line = NULL;
    while ((len = myGetLine(&line)) > 0) {
        char* newLine = entab(line, len + 1, 8);
        printf("%s\n", newLine);
        free(line);
        free(newLine);
    }
    return 0;
}
