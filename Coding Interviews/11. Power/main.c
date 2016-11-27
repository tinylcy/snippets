#include <stdio.h>
#include <stdlib.h>

/*
 * 2.0^2, 2.0^-2, 0.0^2, 0.0^0, 0.0^-2, -2.0^2, -2.0^-2, -2.0^0
 */

double power(double base, int exponent);
double powerWithUnsignedExponent(double base, int exponent);
double powerWithUnsignedExponentRecursive(double base, int exponent); // recursive version
int equal(double x, double y);

int main() {
    printf("power(2.0, 2) = %f\n", power(2.0, 2));
    printf("power(2.0, -2) = %f\n", power(2.0, -2));
    printf("power(0.0, 2) = %f\n", power(0.0, 2));
    printf("power(0.0, 0) = %f\n", power(0.0, 0));
    printf("power(0.0, -2) = %f\n", power(0.0, -2));
    printf("power(-2.0, 2) = %f\n", power(-2.0, 2));
    printf("power(-2.0, -2) = %f\n", power(-2.0, -2));
    printf("power(-2.0, 0) = %f\n", power(-2.0, 0));
    return 0;
}

double power(double base, int exponent) {
    if(equal(0.0, base) && exponent < 0) {
        return -1;
    }
    if(equal(0.0, base) && exponent >= 0) {
        return 0;
    }
    int absExponent = exponent > 0 ? exponent : -exponent;
    double result = 1.0;
    // result = powerWithUnsignedExponent(base, absExponent);
    result = powerWithUnsignedExponentRecursive(base, absExponent);
    if(exponent < 0) {
        result = 1 / result;
    }
    return result;
}

double powerWithUnsignedExponent(double base, int exponent) {
    double result = 1.0;
    int i;
    for(i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

double powerWithUnsignedExponentRecursive(double base, int exponent) {
    if(exponent == 0) {
        return 1;
    }
    if(exponent == 1) {
        return base;
    }
    double result = powerWithUnsignedExponentRecursive(base, exponent >> 1);
    result *= result;
    if(exponent & 0x1 == 1) {
        result *= base;
    }

    return result;
}

int equal(double x, double y) {
    if((x - y >= -0.000001) && (x - y) <= 0.000001) {
        return 1;
    }
    return 0;
}
