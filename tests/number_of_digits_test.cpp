#include <algorithm>

#include <gtest/gtest.h>
#include "../src/solution.h"


TEST(TestTopic, NumberOfDigits1) {
    Solution sol;
    std::string test_data {"+1234"};
    std::ranges::reverse(test_data);

    int expected_result {4};
    int actual_result {sol.numberOfDigits(test_data)};

    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTopic, NumberOfDigits2) {
    Solution sol;
    std::string test_data {"-123456"};
    std::ranges::reverse(test_data);

    int expected_result {6};
    int actual_result {sol.numberOfDigits(test_data)};

    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTopic, NumberOfDigits3) {
    Solution sol;
    std::string test_data {"1234567"};
    std::ranges::reverse(test_data);

    int expected_result {7};
    int actual_result {sol.numberOfDigits(test_data)};

    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTopic, NumberOfDigits4) {
    Solution sol;
    std::string test_data {"123 456789"};
    std::ranges::reverse(test_data);

    int expected_result {3};
    int actual_result {sol.numberOfDigits(test_data)};

    EXPECT_EQ(expected_result, actual_result);
}