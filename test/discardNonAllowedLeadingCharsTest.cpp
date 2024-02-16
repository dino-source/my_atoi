#include <algorithm>
#include <gtest/gtest.h>
#include "../src/solution.h"


TEST(TestTopic, discardMethodDiscardsLeadingSpacesForArgWithPlusSign) {
    Solution sol;
    std::string test_data {"   +1234"};
    std::ranges::reverse(test_data);
    sol.discardNonAllowedLeadingChars(test_data);
    std::string actual_result {test_data};
    std::string expected_result {"4321+"};

    EXPECT_STREQ(actual_result.c_str(), expected_result.c_str());
}

TEST(TestTopic, discardMethodDiscardsLeadingSpacesForArgWithMinusSign) {
    Solution sol;
    std::string test_data {"   -1234"};
    std::ranges::reverse(test_data);
    sol.discardNonAllowedLeadingChars(test_data);
    std::string actual_result {test_data};
    std::string expected_result {"4321-"};

    EXPECT_STREQ(actual_result.c_str(), expected_result.c_str());
}

TEST(TestTopic, discardMethodDiscardsLeadingSpacesForArgWithNoSign) {
    Solution sol;
    std::string test_data {"   1234"};
    std::ranges::reverse(test_data);
    sol.discardNonAllowedLeadingChars(test_data);
    std::string actual_result {test_data};
    std::string expected_result {"4321"};
    
    EXPECT_STREQ(actual_result.c_str(), expected_result.c_str());
}