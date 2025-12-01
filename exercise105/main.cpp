#include "stdio.h"

// Exercise: Modify the temperature conversion program to print
// the table in reverse order, that is, from 300 degrees to 0
int main() {
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("%*s %*s\n", 4, "C", 4, "F");
    printf("%.*d\n", 10, 0);
    for (float celsius = upper; celsius >= lower; celsius -= step) {
        fahr = (9.0 * celsius) / 5.0 + 32.0;
        printf("%6.1f %3.0f\n", celsius, fahr);
    }
    return 0;
}
