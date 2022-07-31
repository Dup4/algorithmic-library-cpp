#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include <string>
#include <vector>

#include "algorithmic/graph/topological_sort.h"

using namespace algorithmic::graph;

class TopologicalSortTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST_F(TopologicalSortTest, TopologicalSort) {
    {
        auto t = TopologicalSort();

        t.SetNumVertices(5).AddEdge(0, 1).AddEdge(1, 0).UpdateTopologicalSort();

        EXPECT_TRUE(t.HasLoop());
    }

    {
        auto t = TopologicalSort();
        t.SetNumVertices(5).AddEdge(0, 1).AddEdge(1, 2).AddEdge(2, 3).AddEdge(3, 4).UpdateTopologicalSort();
        auto res = t.GetTopoLogicalOrder();
        EXPECT_EQ(res, std::vector<int>({0, 1, 2, 3, 4}));
    }
}
