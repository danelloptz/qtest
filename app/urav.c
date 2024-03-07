#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "urav.h"

double* urav(double a, double b, double c) {
    double d = sqrt(b*b - 4*a*c);
    static double arr[2];
    if (b*b - 4*a*c < 0) {
        arr[0] = 1.000000;
        arr[1] = 1.000000;
        return arr;
    }
    if (d > 0) {
        arr[0] = (-b + d) / (2*a);
        arr[1] = (-b - d) / (2*a);
    }
    if (d == 0) {
        arr[0] = (-b) / (2*a);
    }
    return arr;
}

void printStdoutMessagesOther() {
    printf("This is a test message from myfunc.c\n");
    printf("Do not disturb\n");
}
