#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include "algorithmic/data_structure/hash.h"

using namespace std;
using namespace algorithmic::data_structure;

class HashTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST(HashTest, hash_test) {
    const int N = 1e5;
    auto hs = Hash<int>();

    {
        hs.Init(N);
        auto vec = vector<int>({5, 4, 3, 2, 1});

        for (const auto& v : vec) {
            hs.Add(v);
        }

        hs.Gao();

        EXPECT_EQ(hs.GetVec(), vector<int>({
                                       1,
                                       2,
                                       3,
                                       4,
                                       5,
                               }));

        EXPECT_EQ(hs.Size(), 5);
    }
}
