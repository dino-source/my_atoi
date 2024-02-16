#include <algorithm>
#include <gtest/gtest.h>
#include "../src/solution.h"

// The following test cases are to test Solution::hasSign method
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

// The following test cases are to test Solution::isPositive method
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

// The following test cases are to test Solution::isNegative method
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

// The following test cases are to test Solution::fixBounds method
TEST(TestTopic, fixBoundsReturnsUpperBoundIfArgIsGreater) {
    Solution sol;
    long long test_data {9223372036854775807LL};
    EXPECT_EQ(sol.fixBounds(test_data, 1), Solution::UPPER_BOUND);
}

TEST(TestTopic, fixBoundsReturnsLowerBoundIfArgIsLower) {
    Solution sol;
    long long test_data {9223372036854775807LL};
    EXPECT_EQ(sol.fixBounds(test_data, -1), Solution::LOWER_BOUND);
}
