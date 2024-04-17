#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "roots.h"

char rezult[50];

int roots(int a, int b, int c, double *r) {
    double d;
    // printf("%f %f\n", r[0], r[1]);
    r[0] = 0;
    r[1] = 0;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                return -1; // любой корень
            } else {
                return 0; // нет корней
            }
        } else if (c == 0) {
            return 1; // один корень
        } else {
            r[0] = -c / b;
            return 1; // один корень
        }
    }
    else if (b == 0) {
        if (c == 0) {
            return 1; // один корень
        } else {
            r[0] = sqrt(abs(-c / a));
            return 1; // один корень
        }
    }

    d = b * b - 4 * a * c;


    if (d > 0) {
        r[0] = (-b + sqrt(d)) / (2 * a);
        r[1] = (-b - sqrt(d)) / (2 * a);
        return 2; // 2 корня
    }

    else if (d == 0) {
        r[0] = -b / (2 * a);
        return 1; // 1 корень
    }
    else {
        return 0; // нет корней
    }
}

