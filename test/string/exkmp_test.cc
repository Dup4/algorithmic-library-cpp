#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include "algorithmic/string/exkmp.h"

using namespace algorithmic::string;

class ExKMPTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST(ExKMPTest, ex_kmp_test) {
    auto ex_kmp = ExKMP(100);

    {
        const std::string s = "aaaaaa";
        const std::string t = "aaaaaa";
        ex_kmp.GenNext(s);
        EXPECT_EQ(ex_kmp.GetNext(), std::vector<int>({6, 5, 4, 3, 2, 1}));
        ex_kmp.GenExtend(s, t);
        EXPECT_EQ(ex_kmp.GetExtend(), std::vector<int>({6, 5, 4, 3, 2, 1}));
    }
}
