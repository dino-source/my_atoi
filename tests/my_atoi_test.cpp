#include <gtest/gtest.h>
#include "../src/solution.h"


TEST(TestTopic, MyAtoi1) {
    Solution sol;
    std::string test_data {"+1234"};

    int expected_result {1234};
    int actual_result {sol.myAtoi(test_data)};

    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTopic, MyAtoi2) {
    Solution sol;
    std::string test_data {"-1234"};

    int expected_result {-1234};
    int actual_result {sol.myAtoi(test_data)};

    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTopic, MyAtoi3) {
    Solution sol;
    std::string test_data {"1234"};

    int expected_result {1234};
    int actual_result {sol.myAtoi(test_data)};

    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTopic, MyAtoi4) {
    Solution sol;
    std::string test_data {"   +1234"};

    int expected_result {1234};
    int actual_result {sol.myAtoi(test_data)};

    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTopic, MyAtoi5) {
    Solution sol;
    std::string test_data {"   -1234"};

    int expected_result {-1234};
    int actual_result {sol.myAtoi(test_data)};

    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTopic, MyAtoi6) {
    Solution sol;
    std::string test_data {"with words   -1234"};

    int expected_result {0};
    int actual_result {sol.myAtoi(test_data)};

    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTopic, MyAtoi7) {
    Solution sol;
    std::string test_data {""};

    int expected_result {0};
    int actual_result {sol.myAtoi(test_data)};

    EXPECT_EQ(expected_result, actual_result);
}