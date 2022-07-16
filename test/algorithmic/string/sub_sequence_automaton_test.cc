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

        const auto& nx = sub_sequence_automaton.GetNext();

        EXPECT_EQ(nx[1].nx[0], 7);
        EXPECT_EQ(nx[1].nx[1], 2);
        EXPECT_EQ(nx[1].nx[2], 3);
        EXPECT_EQ(nx[1].nx[3], 4);
        EXPECT_EQ(nx[1].nx[4], 5);
        EXPECT_EQ(nx[1].nx[5], 6);
    }
}
