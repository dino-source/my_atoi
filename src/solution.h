#include <string>


class Solution {
public:
    int myAtoi(std::string s);

//private:
    long long charToInt(char ch);
    void discardLeadingSpaces(std::string &s);
    void discardLeadingZeroes(std::string &s);
    char discardSign(std::string &s);
    int fixBounds(long long result, int sign);
    int getSign(const std::string &s) const;
    bool hasLeadingSpaces(const std::string &s) const;
    bool hasLeadingZeros(const std::string &s) const;
    bool hasSign(const std::string &s) const;
    bool isNaN(const std::string &s) const;
    bool isNegative(const std::string &s) const;
    bool isPositive(const std::string &s) const;
    int numberOfDigits(std::string s);
    long long orderOfMagnitude(int number_of_digits) const;

    const long long LOWER_BOUND {-2147483648};
    const long long UPPER_BOUND {2147483647};
};
