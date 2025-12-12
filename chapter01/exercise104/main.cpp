#include "stdio.h"

// Exercise: Write a program to print the corresponding
// Celsius to Fahrenheit table
int main() {
    float celsius, fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;

    printf("%*s %*s\n", 4, "C", 4, "F");
    printf("----------\n");
    while (celsius <= upper) {
        fahr = (9.0 * celsius) / 5.0 + 32.0;
        printf("%6.1f %3.0f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}
