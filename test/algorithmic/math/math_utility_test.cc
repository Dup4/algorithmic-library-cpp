#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include <string>
#include <vector>

#include "algorithmic/math/math_utility.h"

using namespace algorithmic::math;

class MathUtilityTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST_F(MathUtilityTest, gcd_test) {
    {
        EXPECT_EQ(MathUtility::Gcd(0, 0), 0);
        EXPECT_EQ(MathUtility::Gcd(0, 1000000000), 1000000000);
        EXPECT_EQ(MathUtility::Gcd(1, 1), 1);
        EXPECT_EQ(MathUtility::Gcd(1, 2), 1);
    }

    {
        EXPECT_EQ(MathUtility::Gcd<int>({1, 2}), 1);
        EXPECT_EQ(MathUtility::Gcd<int>({}), 0);
        EXPECT_EQ(MathUtility::Gcd<int>({3, 6, 9}), 3);
        EXPECT_EQ(MathUtility::Gcd<int>({2, 4, 6, 8}), 2);
        EXPECT_EQ(MathUtility::Gcd<int>({256, 1024, 512}), 256);
    }
}

TEST_F(MathUtilityTest, lcm_test) {
    {
        EXPECT_EQ(MathUtility::Lcm(1, 1), 1);
        EXPECT_EQ(MathUtility::Lcm(1, 2), 2);
        EXPECT_EQ(MathUtility::Lcm(2, 3), 6);
    }

    {
        auto res = MathUtility::Lcm(int64_t(998244353), int64_t(1000000007));
        EXPECT_EQ(res, 998244359987710471);
    }

    {
        EXPECT_EQ(MathUtility::Lcm<int>({}), 1);
        EXPECT_EQ(MathUtility::Lcm<int>({1, 2}), 2);
        EXPECT_EQ(MathUtility::Lcm<int>({1, 4}), 4);
        EXPECT_EQ(MathUtility::Lcm<int>({3, 6, 9}), 18);
    }
}

TEST_F(MathUtilityTest, quick_pow_test) {
    {
        for (int i = 0; i < 64; i++) {
            EXPECT_EQ(MathUtility::QuickPow<int64_t>(2, i), 1ll << i);
        }
    }
}
