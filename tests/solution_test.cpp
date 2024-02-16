#include <algorithm>
#include <gtest/gtest.h>
#include "../src/solution.h"


TEST(TestTopic, NumberHasSignPlus) {
    Solution sol;
    std::string test_data {"+1234"};
    std::ranges::reverse(test_data);
    EXPECT_TRUE(sol.has_sign(test_data));
}

TEST(TestTopic, NumberHasSignMinus) {
    Solution sol;
    std::string test_data {"-1234"};
    std::ranges::reverse(test_data);
    EXPECT_TRUE(sol.has_sign(test_data));
}

TEST(TestTopic, NumberHasNotAnySign) {
    Solution sol;
    std::string test_data {"1234"};
    std::ranges::reverse(test_data);
    EXPECT_FALSE(sol.has_sign(test_data));
}