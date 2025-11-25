#include "stdio.h"

// Exercise: Verify that the expression
// getchar() != EOF is 0 or 1
int main() {
    int result = getchar() != EOF;
    printf("getchar() != EOF is equals to %d\n", result);
    return 0;
}
