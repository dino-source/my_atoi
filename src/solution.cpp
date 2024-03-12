#include "solution.h"

#include <string>
#include <algorithm>
#include <cctype>


int Solution::myAtoi(std::string s) {
    if (s.empty()) {
        return 0;
    }
    
    if (s.size() == 1 && !std::isdigit(s.front())) {
        return 0;
    }

    std::ranges::reverse(s);
    discardLeadingSpaces(s);
    discardLeadingZeroes(s);

    int number_of_digits = numberOfDigits(s);
    if (number_of_digits == 0 || std::isalpha(s.back())) {
        return 0;
    }
    
    int sign {getSign(s)};

    if (number_of_digits > 10 && sign == 1) {
        return UPPER_BOUND;
    }

    if (number_of_digits > 10 && sign == -1) {
        return LOWER_BOUND;
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

long long Solution::orderOfMagnitude(int number_of_digits) {
    long long order_of_magnitude {1};
    for ([[maybe_unused]] int i {1}; i < number_of_digits; ++i) {
        order_of_magnitude *= 10;
    }
    return order_of_magnitude;
};

void Solution::discardLeadingSpaces(std::string &s) {
    if (hasSign((s))) {
        return;
    }

    int ss = static_cast<int>(s.size());

    for (int i {ss - 1}; i >= 0; --i) {
        if (isspace(s[i])) {
            s.pop_back();
        }
        else {
            return;
        }
    }
};

void Solution::discardLeadingZeroes(std::string &s) {
    char sign {s.back()};
    bool has_sign {false};

    if (hasSign((s))) {
        s.pop_back();
        has_sign = true;
    }

    int ss = static_cast<int>(s.size());

    for (int i {ss - 1}; i >= 0; --i) {
        if (s[i] == '0') {
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
