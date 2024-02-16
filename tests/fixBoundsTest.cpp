#include <algorithm>
#include <gtest/gtest.h>
#include "../src/solution.h"



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
