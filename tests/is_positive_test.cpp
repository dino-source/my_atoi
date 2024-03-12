#include <algorithm>

#include <gtest/gtest.h>
#include "../src/solution.h"


TEST(TestTopic, IsPositiveReturnsTrueIfArgHasPlusSignInTheFront) {
    Solution sol;
    std::string test_data {"+1234"};
    std::ranges::reverse(test_data);
    EXPECT_TRUE(sol.isPositive(test_data));
}

TEST(TestTopic, IsPositiveReturnsTrueIfArgHasNoSign) {
    Solution sol;
    std::string test_data {"1234"};
    std::ranges::reverse(test_data);
    EXPECT_TRUE(sol.isPositive(test_data));
}

TEST(TestTopic, IsPositiveReturnsFalseIfArgHasMinusSignInTheFront) {
    Solution sol;
    std::string test_data {"-1234"};
    std::ranges::reverse(test_data);
    EXPECT_FALSE(sol.isPositive(test_data));
}
