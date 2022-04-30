#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include "algorithmic/string/kmp.h"

using namespace algorithmic::string;

class KMPTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST(KMPTest, kmp_test) {
    auto kmp = KMP(100);

    {
        const std::string s = "aaaaaa";
        const std::string t = "a";
        kmp.GenNext(s);
        EXPECT_EQ(kmp.GetNext(), std::vector<int>({-1, 0, 1, 2, 3, 4, 5}));
        EXPECT_EQ(kmp.MatchString(s, t), std::vector<int>({0, 1, 2, 3, 4, 5}));
    }
}
