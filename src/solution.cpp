#include "solution.h"

#include <cstddef>
#include <string>
#include <algorithm>
#include <cctype>


int Solution::myAtoi(std::string s) {
    if (isNaN(s)) {
        return 0;
    }

    std::ranges::reverse(s);

    if (hasLeadingSpaces(s)) {
        discardLeadingSpaces(s);
        if (isNaN(s)) {
            return 0;
        }
    }

    if (hasLeadingZeros(s)) {
        discardLeadingZeroes(s);
        if (isNaN(s) || s.back() == '-' || s.back() == '+' ) {
            return 0;
        }
    }

    if (hasSign(s)) {
        char sign {discardSign(s)};
        discardLeadingZeroes(s);
        if (isNaN(s)) {
            return 0;
        }
        s.push_back(sign);
    }

    int number_of_digits = numberOfDigits(s);
    if (number_of_digits == 0 || std::isalpha(s.back())) {
        return 0;
    }
    
    int sign {getSign(s)};

    if (number_of_digits > 10 && sign == 1) {
        return static_cast<int>(UPPER_BOUND);
    }

    if (number_of_digits > 10 && sign == -1) {
        return static_cast<int>(LOWER_BOUND);
    }

    long long result {};
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
    return static_cast<long long>(ch) - 48;
};

void Solution::discardLeadingSpaces(std::string &s) {
    if (hasSign((s))) {
        return;
    }

    int ss = static_cast<int>(s.size());

    for (int i {ss - 1}; i >= 0; --i) {
        if (isspace(s[static_cast<std::size_t>(i)])) {
            s.pop_back();
        }
        else {
            return;
        }
    }
};

void Solution::discardLeadingZeroes(std::string &s) {
    [[maybe_unused]] char sign;
    [[maybe_unused]] bool has_sign {false};

    if (hasSign((s))) {
        sign = discardSign(s);
        has_sign = true;
    }

    int ss = static_cast<int>(s.size());

    for (int i {ss - 1}; i >= 0; --i) {
        if (s[static_cast<std::size_t>(i)] == '0') {
            s.pop_back();
        }
        else {
            if (has_sign) {
                s.push_back(sign);
            }
            return;
        }
    }
}

char Solution::discardSign(std::string &s) {
    char sign = s.back();
    s.pop_back();
    return sign;
}

int Solution::fixBounds(long long result, int sign) {   
    result *= sign;
    if (result > UPPER_BOUND) {
        result = UPPER_BOUND;
    }
    else if (result < LOWER_BOUND) {
        result = LOWER_BOUND;
    }
    return static_cast<int>(result);
};

int Solution::getSign(const std::string &s) const {
    int sign {};
    if (isPositive(s)) {
        sign = 1;
    }
    else if (isNegative(s)) {
        sign = -1;
    }

    return sign;
};

bool Solution::hasLeadingSpaces(const std::string &s) const {
    return s.back() == ' ';
}

bool Solution::hasLeadingZeros(const std::string &s) const {
    return s.back() == '0';
}

bool Solution::hasSign(const std::string &s) const {
    return s.back() == '+' || s.back() == '-';
}

bool Solution::isNaN(const std::string &s) const {
    return s.empty() ||
        (s.size() == 1 && !std::isdigit(s.front()));
}

bool Solution::isNegative(const std::string &s) const {
    return s.back() == '-';
}

bool Solution::isPositive(const std::string &s) const {
    return !isNegative(s);
}

int Solution::numberOfDigits(std::string s) {
    if (hasSign(s)) {
        s.pop_back();
    }

    int number_of_digits {0};
    
    for (auto it = s.crbegin(); it != s.crend(); ++it) {
        if (std::isdigit(*it)) {
            ++number_of_digits;
        }
        else {
            break;
        }
    }

    return number_of_digits;
};

long long Solution::orderOfMagnitude(int number_of_digits) const {
    long long order_of_magnitude {1};
    for ([[maybe_unused]] int i {1}; i < number_of_digits; ++i) {
        order_of_magnitude *= 10;
    }
    return order_of_magnitude;
};
