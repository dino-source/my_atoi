#include <gtest/gtest.h>
#include "../src/solution.h"


TEST(TestTopic, myAtoiConvertsArgWithoutSignToPositiveNumber) {
    Solution sol;
    std::string test_data {"1234"};
    EXPECT_EQ(sol.myAtoi(test_data), 1234);
}

TEST(TestTopic, myAtoiConvertsArgWithPlusSignToPositiveNumber) {
    Solution sol;
    std::string test_data {"+1234"};
    EXPECT_EQ(sol.myAtoi(test_data), 1234);
}

TEST(TestTopic, myAtoiConvertsArgWithMinusSignToNegativeNumber) {
    Solution sol;
    std::string test_data {"-1234"};
    EXPECT_EQ(sol.myAtoi(test_data), -1234);
}

TEST(TestTopic, myAtoiReturnsZeroIfArgIsNotANumber) {
    Solution sol;
    std::string test_data {"AAAA"};
    EXPECT_EQ(sol.myAtoi(test_data), 0);
}

TEST(TestTopic, myAtoiReturnsZeroIfArgIsEmptyString) {
    Solution sol;
    std::string test_data {""};
    EXPECT_EQ(sol.myAtoi(test_data), 0);
}