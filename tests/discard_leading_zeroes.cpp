#include <algorithm>

#include <gtest/gtest.h>
#include "../src/solution.h"


TEST(TestTopic, DiscardLeadingZeros1) {
    Solution sol;
    std::string test_data {"00001234"};
    std::ranges::reverse(test_data);

    std::string expected_result {"4321"};
    sol.discardLeadingZeroes(test_data);
    std::string actual_result {test_data};

    EXPECT_STREQ(expected_result.c_str(), actual_result.c_str());
}

TEST(TestTopic, DiscardLeadingZeros2) {
    Solution sol;
    std::string test_data {"-00001234"};
    std::ranges::reverse(test_data);

    std::string expected_result {"4321-"};
    sol.discardLeadingZeroes(test_data);
    std::string actual_result {test_data};

    EXPECT_STREQ(expected_result.c_str(), actual_result.c_str());
}

TEST(TestTopic, DiscardLeadingZeros3) {
    Solution sol;
    std::string test_data {"000000000000000000"};
    std::ranges::reverse(test_data);

    std::string expected_result {""};
    sol.discardLeadingZeroes(test_data);
    std::string actual_result {test_data};

    EXPECT_STREQ(expected_result.c_str(), actual_result.c_str());
}

TEST(TestTopic, DiscardLeadingZeros4) {
    Solution sol;
    std::string test_data {"-000000000000000000"};
    std::ranges::reverse(test_data);

    std::string expected_result {""};
    sol.discardLeadingZeroes(test_data);
    std::string actual_result {test_data};

    EXPECT_STREQ(expected_result.c_str(), actual_result.c_str());
}

TEST(TestTopic, DiscardLeadingZeros5) {
    Solution sol;
    std::string test_data {"-000000000000001"};
    std::ranges::reverse(test_data);

    std::string expected_result {"1-"};
    sol.discardLeadingZeroes(test_data);
    std::string actual_result {test_data};

    EXPECT_STREQ(expected_result.c_str(), actual_result.c_str());
}


