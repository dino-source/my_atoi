#include <string>


class Solution {
public:
    int myAtoi(std::string s);

//private:
    long long charToInt(char ch);
    int numberOfDigits(std::string s);
    long long orderOfMagnitude(int number_of_digits);
    void discardLeadingNonAllowedChars(std::string &s);
    int getSign(std::string &s);
    int fix_bounds(long long result, int sign);
    bool has_sign(const std::string &s);
    bool is_negative(const std::string &s);
    bool is_positive(const std::string &s);
};
