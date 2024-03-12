#include <gtest/gtest.h>
#include "../src/solution.h"


TEST(TestTopic, OrderOfMagnitude1) {
    Solution sol;
    int test_data {0};

    int expected_result {1};
    int actual_result {static_cast<int>(sol.orderOfMagnitude(test_data))};

    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTopic, OrderOfMagnitude2) {
    Solution sol;
    int test_data {1};

    int expected_result {1};
    int actual_result {static_cast<int>(sol.orderOfMagnitude(test_data))};

    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTopic, OrderOfMagnitude3) {
    Solution sol;
    int test_data {2};

    int expected_result {10};
    int actual_result {static_cast<int>(sol.orderOfMagnitude(test_data))};

    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTopic, OrderOfMagnitude4) {
    Solution sol;
    int test_data {3};

    int expected_result {100};
    int actual_result {static_cast<int>(sol.orderOfMagnitude(test_data))};

    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTopic, OrderOfMagnitude5) {
    Solution sol;
    int test_data {4};

    int expected_result {1000};
    int actual_result {static_cast<int>(sol.orderOfMagnitude(test_data))};

    EXPECT_EQ(expected_result, actual_result);
}