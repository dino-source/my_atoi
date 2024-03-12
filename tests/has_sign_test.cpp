#include <algorithm>

#include <gtest/gtest.h>
#include "../src/solution.h"


TEST(TestTopic, HasSignReturnsTrueIfArgHasPlusSignInTheFront) {
    Solution sol;
    std::string test_data {"+1234"};
    std::ranges::reverse(test_data);
    EXPECT_TRUE(sol.hasSign(test_data));
}

TEST(TestTopic, HasSignReturnsTrueIfArgHasMinusSignInTheFront) {
    Solution sol;
    std::string test_data {"-1234"};
    std::ranges::reverse(test_data);
    EXPECT_TRUE(sol.hasSign(test_data));
}

TEST(TestTopic, HasSignReturnsFalseIfArgHasNoSign) {
    Solution sol;
    std::string test_data {"1234"};
    std::ranges::reverse(test_data);
    EXPECT_FALSE(sol.hasSign(test_data));
}

TEST(TestTopic, HasSignReturnsFalseIfArgHasMinusSignInTheBack) {
    Solution sol;
    std::string test_data {"1234-"};
    std::ranges::reverse(test_data);
    EXPECT_FALSE(sol.hasSign(test_data));
}

TEST(TestTopic, HasSignReturnsFalseIfArgHasPlusSignInTheBack) {
    Solution sol;
    std::string test_data {"1234+"};
    std::ranges::reverse(test_data);
    EXPECT_FALSE(sol.hasSign(test_data));
}

TEST(TestTopic, HasSignReturnsFalseIfArgHasMinusSignInTheMiddle) {
    Solution sol;
    std::string test_data {"12-34"};
    std::ranges::reverse(test_data);
    EXPECT_FALSE(sol.hasSign(test_data));
}

TEST(TestTopic, HasSignReturnsFalseIfArgHasPlusSignInTheMiddle) {
    Solution sol;
    std::string test_data {"12+34"};
    std::ranges::reverse(test_data);
    EXPECT_FALSE(sol.hasSign(test_data));
}
