#include "gtest/gtest.h"

#include "algorithmic/string/manacher.h"

using namespace algorithmic;

class ManacherTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST(ManacherTest, manacher_test) {
    auto manacher = Manacher(10);
}
