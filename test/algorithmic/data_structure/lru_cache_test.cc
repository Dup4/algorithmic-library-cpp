#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include "algorithmic/data_structure/lru_cache.h"

using namespace std;
using namespace algorithmic::data_structure;

class LRUCacheTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST(LRUCacheTest, lru_cache_test) {
    auto lru_cache = LRUCache<int, int>(5);

    {
        lru_cache.Put(1, 1);
        EXPECT_EQ(lru_cache.Get(1).value(), 1);
        lru_cache.Clear();
    }

    {
        EXPECT_FALSE(lru_cache.Get(1).has_value());

        for (int i = 1; i <= 5; i++) {
            lru_cache.Put(i, i);
            EXPECT_EQ(lru_cache.Get(i).value(), i);
        }

        for (int i = 6; i <= 10; i++) {
            lru_cache.Put(i, i);
            EXPECT_EQ(lru_cache.Get(i), i);
            EXPECT_FALSE(lru_cache.Get(i - 5).has_value());
        }
    }
}
