#ifndef URAVNENIE_H
#define URAVNENIE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern "C" {
#include "urav.h"
}

TEST(Urav, num0) {
    double* rez = urav(1, -5, 4);
    double need[2] = {4.000000, 1.000000};

    EXPECT_TRUE(rez[0] == need[0]);
    EXPECT_TRUE(rez[1] == need[1]);
}
TEST(Urav, num1) {
    double* rez = urav(1, -3, 2);
    double need[2] = {2.000000, 1.000000};

    EXPECT_TRUE(rez[0] == need[0]);
    EXPECT_TRUE(rez[1] == need[1]);
}
TEST(Urav, num2) {
    double* rez = urav(1, -13, 12);
    double need[2] = {12.000000, 1.000000};

    EXPECT_TRUE(rez[0] == need[0]);
    EXPECT_TRUE(rez[1] == need[1]);
}
TEST(Urav, num3) {
    double* rez = urav(1, 3, 12);
    double need[2] = {1.000000, 1.000000};

    EXPECT_TRUE(rez[0] == need[0]);
    EXPECT_TRUE(rez[1] == need[1]);
}
TEST(Urav, num4) {
    double* rez = urav(1, 2, 1);
    double need[1] = {-1.000000};

    EXPECT_TRUE(rez[0] == need[0]);
}

#endif // URAVNENIE_H
