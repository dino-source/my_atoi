#include <algorithm>

#include <gtest/gtest.h>
#include "../src/solution.h"


TEST(TestTopic, DiscardLeadingSpaces1) {
    Solution sol;
    std::string test_data {"   1234"};
    std::ranges::reverse(test_data);

    std::string expected_result {"4321"};
    sol.discardLeadingSpaces(test_data);
    std::string actual_result {test_data};

    EXPECT_STREQ(expected_result.c_str(), actual_result.c_str());
}

TEST(TestTopic, DiscardLeadingSpaces2) {
    Solution sol;
    std::string test_data {"   -1234"};
    std::ranges::reverse(test_data);

    std::string expected_result {"4321-"};
    sol.discardLeadingSpaces(test_data);
    std::string actual_result {test_data};

    EXPECT_STREQ(expected_result.c_str(), actual_result.c_str());
}

TEST(TestTopic, DiscardLeadingSpaces3) {
    Solution sol;
    std::string test_data {"   +1234"};
    std::ranges::reverse(test_data);

    std::string expected_result {"4321+"};
    sol.discardLeadingSpaces(test_data);
    std::string actual_result {test_data};

    EXPECT_STREQ(expected_result.c_str(), actual_result.c_str());
}

TEST(TestTopic, DiscardLeadingSpaces4) {
    Solution sol;
    std::string test_data {"   +12 34"};
    std::ranges::reverse(test_data);

    std::string expected_result {"43 21+"};
    sol.discardLeadingSpaces(test_data);
    std::string actual_result {test_data};

    EXPECT_STREQ(expected_result.c_str(), actual_result.c_str());
}

TEST(TestTopic, DiscardLeadingSpaces5) {
    Solution sol;
    std::string test_data {"   "};
    std::ranges::reverse(test_data);

    std::string expected_result {""};
    sol.discardLeadingSpaces(test_data);
    std::string actual_result {test_data};

    EXPECT_STREQ(expected_result.c_str(), actual_result.c_str());
}
