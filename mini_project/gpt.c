#include <stdio.h>
#include <math.h>

double function(double x) {
    // Define your function here
    return cos(x); // Example function (sine function)
}

double forwardDifference(double x, double h) {
    return (function(x + h) - function(x-h)) / h;
}

int main() {
    double x = 0.5; // The point at which to compute the derivative
    double h = 0.001; // Step size

    double derivative = forwardDifference(x, h);

    printf("The derivative of the function at x = %.2f is: %.6f\n", x, derivative);

    return 0;
}

