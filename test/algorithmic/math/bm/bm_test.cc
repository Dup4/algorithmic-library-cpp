#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include <iostream>
#include <limits>

#include "algorithmic/math/bm/bm_prime.h"

TEST(BMPrimeTest, bm_prime_test) {
    {
        auto bm = algorithmic::math::BMPrime<100000>();

        int n = 1e5;
        auto res = bm.Gao({1, 5, 11, 36, 95, 281, 781, 2245, 6336, 18061, 51205}, n - 1);

        EXPECT_EQ(res, 472844846);
    }

    {
        auto bm = algorithmic::math::BMPrime<100000>::Builder().WithMod(998244353).Build();

        int n = 1e5;
        auto res = bm.Gao({1, 5, 11, 36, 95, 281, 781, 2245, 6336, 18061, 51205}, n - 1);

        EXPECT_EQ(res, 726789438);
    }
}
