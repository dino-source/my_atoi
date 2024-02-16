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
    if (has_sign(s)) {
        s.pop_back();
    }

    for (int nod {number_of_digits}; nod > 0; --nod) {
        if (std::isdigit(s.back())) {
            result += charToInt(s.back()) * orderOfMagnitude(nod);
            s.pop_back();
        }
        else {
            return fix_bounds(result, sign);
        }
    }

    return fix_bounds(result, sign);
}

long long Solution::charToInt(char ch) {
    return static_cast<int>(ch) - 48;
};

int Solution::numberOfDigits(std::string s) {
    char sign {};
    bool has_sign_as_first_char {false};
    if (has_sign(s)) {
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
        if (has_sign((s))) {
            return;
        }
    }
};

int Solution::getSign(std::string &s) {
    int sign {};
    if (is_positive(s)) {
        sign = 1;
    }
    else if (is_negative(s)) {
        sign = -1;
    }

    return sign;
};

int Solution::fix_bounds(long long result, int sign) {
    result *= sign;
    if (result > 2147483647) {
        result = 2147483647;
    }
    if (result < -2147483648) {
        result = -2147483648;
    }
    return static_cast<int>(result);
};

bool Solution::has_sign(const std::string &s) {
    return s.back() == '+' || s.back() == '-';
}

bool Solution::is_negative(const std::string &s) {
    return s.back() == '-';
}

bool Solution::is_positive(const std::string &s) {
    return s.back() == '+' || std::isdigit(s.back());
}
