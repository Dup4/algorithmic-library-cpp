#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include <iostream>
#include <limits>

#include "algorithmic/misc/detect_compiler.h"

class DetectCompilerTest : public testing::Test {
public:
};

TEST_F(DetectCompilerTest, detect_compiler) {
    SNAPSHOT(algorithmic::misc::DetectCompiler::Detect());
}
