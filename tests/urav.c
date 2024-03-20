#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "urav.h"

char rez[50];

char* urav(int a, int b, int c) {
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
            sprintf(rez, "%.2lf", x1);
            return rez;
        }
    }
    else if (b == 0) {
        if (c == 0) {
            return "0";
        } else {
            x1 = sqrt(abs(-c / a));
            sprintf(rez, "%.2lf : %.2lf", x1, -x1);
            return rez;
        }
    }

    d = b * b - 4 * a * c;


    if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        sprintf(rez, "%.2lf : %.2lf", x1, x2);
        return rez;
    }

    else if (d == 0) {
        x1 = -b / (2 * a);
        sprintf(rez, "%.2lf", x1);
        return rez;
    }
    else {
        return "Корней нет";
    }
}

