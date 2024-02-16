#include <algorithm>
#include <gtest/gtest.h>
#include "../src/solution.h"


TEST(TestTopic, IsNegativeReturnsTrueIfArgHasMinusSignInTheFront) {
    Solution sol;
    std::string test_data {"-1234"};
    std::ranges::reverse(test_data);
    EXPECT_TRUE(sol.isNegative(test_data));
}

TEST(TestTopic, IsNegativeReturnsFalseIfArgHasPlusSignInTheFront) {
    Solution sol;
    std::string test_data {"+1234"};
    std::ranges::reverse(test_data);
    EXPECT_FALSE(sol.isNegative(test_data));
}

TEST(TestTopic, IsNegativeReturnsFalseIfArgHasNoSign) {
    Solution sol;
    std::string test_data {"1234"};
    std::ranges::reverse(test_data);
    EXPECT_FALSE(sol.isNegative(test_data));
}
