#include "stdio.h"

// Exercise: Experiment to find out what happens
// when printf's argument string contains \c,
// where c is some character not listed above
int main() {
    printf("\a\n");
    printf("\b\n");
    printf("\e\n");
    printf("\f\n");
    return 0;
}
