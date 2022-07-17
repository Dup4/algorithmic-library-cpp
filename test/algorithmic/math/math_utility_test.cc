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
}
