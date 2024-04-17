#include <stdio.h>
#include <stdlib.h>

#include "myfunc.h"
#include "roots.h"

int main() {
    
    double *r = (double *) malloc(sizeof(double) * 2);
    int status = roots(1, -5, 4, r);
    printf("%d\n", status);
    printf("%f %f", r[0], r[1]);

    return 0;
}
