#include <stdio.h>
#include <stdlib.h>

#include "myfunc.h"
#include "urav.h"

int main() {
    printf("Hello World!\n");

    double* rez;
    rez = urav(1, -5, 4);

    return 0;
}
