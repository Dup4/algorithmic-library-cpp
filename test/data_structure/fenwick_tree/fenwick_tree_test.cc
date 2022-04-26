#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include "algorithmic/data_structure/fenwick_tree/fenwick_tree.h"

using namespace std;
using namespace algorithmic::data_structure;

class FenwickTreeTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST(FenwickTreeTest, fenwick_tree_test) {
    const int N = 1e5;
    auto fenwick_tree = fenwick_tree::FenwickTree<int, N>();

    {
        fenwick_tree.Init(10);
        fenwick_tree.Add(1, 10);
        fenwick_tree.Add(10, 10);
        EXPECT_EQ(fenwick_tree.Query(1), 10);
        EXPECT_EQ(fenwick_tree.Query(10), 20);
        EXPECT_EQ(fenwick_tree.Query(1, 10), 20);
    }

    {
        fenwick_tree.Init(100);
        for (int i = 1; i <= 100; i++) {
            fenwick_tree.Add(i, 1);
            EXPECT_EQ(fenwick_tree.QueryKth(i), i);
        }
    }
}
