#include <string>


class Solution {
public:
    static constexpr int UPPER_BOUND {2147483647};
    static constexpr int LOWER_BOUND {-2147483648};
    int myAtoi(std::string s);

//private:
    long long charToInt(char ch);
    int numberOfDigits(std::string s);
    long long orderOfMagnitude(int number_of_digits);
    void discardNonAllowedLeadingChars(std::string &s);
    int getSign(std::string &s);
    int fixBounds(long long result, int sign);
    bool hasSign(const std::string &s);
    bool isNegative(const std::string &s);
    bool isPositive(const std::string &s);
};
