#include "stdio.h"

float convertFahrenheitToCelsius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}

// Exercise: Rewrite the temperature conversion program
// of Section 1.12 to use a function for conversion
int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("%*s %*s\n", 2, "F", 5, "C");
    printf("%.*d\n", 10, 0);
    while (fahr <= upper) {
        celsius = convertFahrenheitToCelsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }
    return 0;
}
