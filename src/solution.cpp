#include "solution.h"

#include <string>
#include <algorithm>
#include <cctype>


int Solution::myAtoi(std::string s) {
    std::ranges::reverse(s);

    int number_of_digits = numberOfDigits(s);
    if (s.empty() || number_of_digits == 0) {
        return 0;
    }

    discardLeadingNonAllowedChars(s);

    long long result {};
    int sign {getSign(s)};
    if (hasSign(s)) {
        s.pop_back();
    }

    for (int nod {number_of_digits}; nod > 0; --nod) {
        if (std::isdigit(s.back())) {
            result += charToInt(s.back()) * orderOfMagnitude(nod);
            s.pop_back();
        }
        else {
            return fixBounds(result, sign);
        }
    }

    return fixBounds(result, sign);
}

long long Solution::charToInt(char ch) {
    return static_cast<int>(ch) - 48;
};

int Solution::numberOfDigits(std::string s) {
    char sign {};
    bool has_sign_as_first_char {false};
    if (hasSign(s)) {
        sign = s.back();
        s.pop_back();
        has_sign_as_first_char = true;
    }

    int number_of_digits {};
    for (const auto ch : s) {
        if (std::isdigit(ch)) {
            ++number_of_digits;
        }
        else {
            if (has_sign_as_first_char) {
                s.push_back(sign);
            }
            return number_of_digits;
        }
    }
    if (has_sign_as_first_char) {
        s.push_back(sign);
    }
    return number_of_digits;
};

long long Solution::orderOfMagnitude(int number_of_digits) {
    long long order_of_magnitude {1};
    for ([[maybe_unused]] int i {1}; i < number_of_digits; ++i) {
        order_of_magnitude *= 10;
    }
    return order_of_magnitude;
};

void Solution::discardLeadingNonAllowedChars(std::string &s) {
    // This function will discard all non digit characters,
    // except of sign '+' and sign '-'
    while (!std::isdigit(s.back())) {
        s.pop_back();
        if (hasSign((s))) {
            return;
        }
    }
};

int Solution::getSign(std::string &s) {
    int sign {};
    if (isPositive(s)) {
        sign = 1;
    }
    else if (isNegative(s)) {
        sign = -1;
    }

    return sign;
};

int Solution::fixBounds(long long result, int sign) {
    const int UPPER_BOUND {2147483647};
    const int LOWER_BOUND {-2147483648};
    
    result *= sign;
    if (result > UPPER_BOUND) {
        result = UPPER_BOUND;
    }
    else if (result < LOWER_BOUND) {
        result = LOWER_BOUND;
    }
    return static_cast<int>(result);
};

bool Solution::hasSign(const std::string &s) {
    return s.back() == '+' || s.back() == '-';
}

bool Solution::isNegative(const std::string &s) {
    return s.back() == '-';
}

bool Solution::isPositive(const std::string &s) {
    return !isNegative(s);
}
