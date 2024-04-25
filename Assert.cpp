//
// Created by Володя on 19.04.2024.
//

#include "Assert.h"

void assert_not_empty(const std::string &value, const std::string &label) {
    if (value.empty()) {
        throw std::invalid_argument(label + " must be not empty");
    }
}

void assert_not_less_than_n(int value, int n, const std::string &label) {
    if (value < n) {
        throw std::invalid_argument(
                label + " (" + std::to_string(value) + ")" + " must be not less than " + std::to_string(n));
    }
}

void assert_greater_than_n(int value, int n, const std::string &label) {
    if (value <= n) {
        throw std::invalid_argument(
                label + " (" + std::to_string(value) + ")" + " must be greater than " + std::to_string(n));
    }
}

void assert_not_greater_than_n(int value, int n, const std::string &label) {
    if (value > n) {
        throw std::invalid_argument(
                label + " (" + std::to_string(value) + ")" + " must not be greater than " + std::to_string(n));
    }
}

void assert_course_in(int value, int left, int right, const std::string &label) {
    if (value < left || value > right) {
        throw std::invalid_argument(
                label + " (" + std::to_string(value) + ")" + " must course in [" + std::to_string(left) + "," +
                std::to_string(right) + "]");
    }
}


void assert_number(const std::string &value, const std::string &label) {
    for (const auto &item: value) {
        if (!isdigit(item))
            throw std::invalid_argument(
                    label + " (" + value + ")" + " is not a number");
    }
}

void assert_true(bool value, const std::string &label) {
    if (!value) {
        throw std::logic_error(label + "must be true");
    }
}


