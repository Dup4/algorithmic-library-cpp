#include <gtest/gtest.h>

#include "algorithmic-library/hello_world.h"

TEST(HELLO_WORLD, hello_world) {
    EXPECT_EQ(HelloWorld(), "Hello World");
}
