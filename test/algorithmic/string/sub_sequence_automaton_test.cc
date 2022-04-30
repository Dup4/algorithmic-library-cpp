#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include "algorithmic/string/sub_sequence_automaton.h"

using namespace algorithmic::string;

class SubSequenceAutomatonTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST(SubSequenceAutomatonTest, sub_sequence_automaton_test) {
    auto sub_sequence_automaton = SubSequenceAutomaton<26>(100);

    {
        const std::string s = "abcdefabcdef";
        sub_sequence_automaton.Build(s);

        EXPECT_TRUE(sub_sequence_automaton.MatchSubSequence("aa"));
        EXPECT_TRUE(sub_sequence_automaton.MatchSubSequence("bb"));
    }
}
