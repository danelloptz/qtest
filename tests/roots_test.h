#ifndef URAVNENIE_H
#define URAVNENIE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern "C" {
#include "roots.h"
}
double *r = (double *) malloc(sizeof(double) * 2);
int status;

TEST(Roots, BASIC) {
    status = roots(1, -5, 4, r);

    ASSERT_EQ(status, 2);
    ASSERT_EQ(r[0], 4);
    ASSERT_EQ(r[1], 1);

    status = roots(1, -3, 2, r);
    ASSERT_EQ(r[0], 2);
    ASSERT_EQ(r[1], 1);

}

TEST(Roots, NOREZULT) {
    status = roots(1, 3, 12, r);
    ASSERT_EQ(status, 0);  

    status = roots(0, 0, 1, r);
    ASSERT_EQ(status, 0);
}

TEST(Roots, ONEREZULT) {
    status = roots(1, 2, 1, r);
    ASSERT_EQ(status, 1); 
    ASSERT_EQ(r[0], -1);

    status = roots(0, 1, 0, r);
    ASSERT_EQ(status, 1); 
    ASSERT_EQ(r[0], 0);

    status = roots(1, 0, 0, r);
    ASSERT_EQ(status, 1); 
    ASSERT_EQ(r[0], 0);

    status = roots(0, 1, 2, r);
    ASSERT_EQ(status, 1); 
    ASSERT_EQ(r[0], -2);
}

TEST(Roots, ANY) {
    status = roots(0, 0, 0, r);
    ASSERT_EQ(status, -1); 
}

TEST(RootsTest, inputFile) {
    char *file = (char *)malloc(sizeof(char) * 1024);
    sprintf(file, "%s/input.txt", INPUTDIR);

    int input = open(file, O_RDONLY);
    free(file);
    if (input < 0) {
        ASSERT_EQ(errno, 0);
    }

    char *buffer = (char *)malloc(sizeof(char) * 512);
    int symb = read(input, buffer, 512);
    ASSERT_TRUE(symb > 0);
    close(input);

    int a = 0;
    int b =0;
    int c = 0;
    int output;
    int rezult = sscanf(buffer, "%d %d %d %d", &a, &b, &c, &output);
    printf("%d \n", output);
    free(buffer);

    ASSERT_EQ(rezult, 4);

    status = roots(a, b, c, r);
    ASSERT_EQ(status, 1); 
    ASSERT_EQ(r[0], output);

}

#endif // URAVNENIE_H
