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

TEST(Roots, basic) {
    ASSERT_STREQ(roots(1, -5, 4), "4.00 : 1.00");
    ASSERT_STREQ(roots(1, -3, 2), "2.00 : 1.00");
    ASSERT_STREQ(roots(1, -13, 12), "12.00 : 1.00");
}
TEST(Roots, norezult) {
    ASSERT_STREQ(roots(1,3,12), "Корней нет");   
    ASSERT_STREQ(roots(0,0,1), "Нет корней");
}
TEST(Roots, onerezult) {
    ASSERT_STREQ(roots(1,2,1), "-1.00");
    ASSERT_STREQ(roots(0,1,0), "0");
    ASSERT_STREQ(roots(1,0,0), "0");
    ASSERT_STREQ(roots(0,1,2), "-2.00");
}

TEST(Roots, other) {
    ASSERT_STREQ(roots(0,0,0), "Любой x");
    ASSERT_STREQ(roots(1,0,4), "2.00 : -2.00");
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
    char output[20];
    int rezult = sscanf(buffer, "%d %d %d %s", &a, &b, &c, output);
    free(buffer);

    ASSERT_EQ(rezult, 4);
    ASSERT_STREQ(roots(a,b,c), output);
}

#endif // URAVNENIE_H
