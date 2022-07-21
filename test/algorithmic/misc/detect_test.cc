#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include <iostream>
#include <limits>

#include "algorithmic/misc/detect.h"

class DetectTest : public testing::Test {
public:
};

TEST_F(DetectTest, detect_compiler) {
    SNAPSHOT(algorithmic::misc::Detect::Compiler());
}
