#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "roots.h"

char rezult[50];

char* roots(int a, int b, int c) {
    double x1, x2, d;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                return "Любой x";
            } else {
                return "Нет корней";
            }
        } else if (c == 0) {
            return "0";
        } else {
            x1 = -c / b;
            sprintf(rezult, "%.2lf", x1);
            return rezult;
        }
    }
    else if (b == 0) {
        if (c == 0) {
            return "0";
        } else {
            x1 = sqrt(abs(-c / a));
            sprintf(rezult, "%.2lf : %.2lf", x1, -x1);
            return rezult;
        }
    }

    d = b * b - 4 * a * c;


    if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        sprintf(rezult, "%.2lf : %.2lf", x1, x2);
        return rezult;
    }

    else if (d == 0) {
        x1 = -b / (2 * a);
        sprintf(rezult, "%.2lf", x1);
        return rezult;
    }
    else {
        return "Корней нет";
    }
}

