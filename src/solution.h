#include <string>


class Solution {
public:
    int myAtoi(std::string s);

//private:
    long long charToInt(char ch);
    int numberOfDigits(std::string s);
    long long orderOfMagnitude(int number_of_digits);
    void discardLeadingSpaces(std::string &s);
    void discardLeadingZeroes(std::string &s);
    int getSign(std::string &s);
    int fixBounds(long long result, int sign);
    bool hasSign(const std::string &s);
    bool isNegative(const std::string &s);
    bool isPositive(const std::string &s);

    const long long UPPER_BOUND {2147483647};
    const long long LOWER_BOUND {-2147483648};
};
