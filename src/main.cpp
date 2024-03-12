#include <iostream>
#include <algorithm>
#include "solution.h"

int main() {
    Solution sol;
    std::string test_data {"+1234"};
    std::ranges::reverse(test_data);
    std::cout << test_data << '\n';
}