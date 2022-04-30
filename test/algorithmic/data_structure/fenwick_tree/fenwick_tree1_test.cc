#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include "algorithmic/data_structure/fenwick_tree/fenwick_tree1.h"

using namespace std;
using namespace algorithmic::data_structure;

class FenwickTree1Test : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST(FenwickTree1Test, fenwick_tree1_test) {
    const int N = 1e5;
    auto fenwick_tree = fenwick_tree::FenwickTree<int>(N);

    {
        fenwick_tree.Init(10);
        fenwick_tree.Add(1, 1, 10);
        fenwick_tree.Add(1, 10, 10);
        EXPECT_EQ(fenwick_tree.Query(1), 20);
        EXPECT_EQ(fenwick_tree.Query(10), 10);
    }
}
