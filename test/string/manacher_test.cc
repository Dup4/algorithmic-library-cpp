#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include "algorithmic/string/manacher.h"

using namespace algorithmic;

class ManacherTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST(ManacherTest, manacher_test) {
    auto manacher = Manacher(100);

    {
        const std::string s = "aaaaaa";
        manacher.Build(s);

        EXPECT_EQ(manacher.GetMaxLengthOfPalindromeSubstring(), 6);
        EXPECT_TRUE(manacher.IsPalindrome(0, 5));
        EXPECT_EQ(manacher.GetU(), std::vector<int>({1, 1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1}));
    }
}
