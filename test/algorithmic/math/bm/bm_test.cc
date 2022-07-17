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

// https://leetcode.cn/problems/count-the-number-of-ideal-arrays/
TEST(BMPrimeTest, bm_prime_test_1) {
    const auto sol = [](int n, int maxValue) {
        const int N = 100;
        const int mod = 1000000007;

        auto f = std::vector<std::vector<int>>(N + 1, std::vector<int>(maxValue + 5, 0));

        for (int i = 1; i <= maxValue; i++) {
            f[1][i] = 1;
        }

        for (int i = 1; i < N; i++) {
            auto &cur = f[i];
            auto &nx = f[i + 1];

            for (int j = 1; j <= maxValue; j++) {
                for (int k = 1; j * k <= maxValue; k++) {
                    nx[int(j * k)] += cur[j];
                    nx[int(j * k)] %= mod;
                }
            }
        }

        auto g = std::vector<long long>();

        for (int i = 1; i <= N; i++) {
            g.push_back(0);
            for (int j = 1; j <= maxValue; j++) {
                g.back() += f[i][j];
                g.back() %= mod;
            }
        }

        if (n <= N) {
            return g[n - 1];
        }

        auto bm = algorithmic::math::BMPrime<100000>::Builder().WithMod(mod).Build();
        return bm.Gao(g, n - 1);
    };

    EXPECT_EQ(sol(10000, 10000), 22940607);
    EXPECT_EQ(sol(5000, 10000), 553451492);
    EXPECT_EQ(sol(9999, 9999), 984922380);
}
