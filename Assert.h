//
// Created by Володя on 18.04.2024.
//

#pragma once

#include <iostream>

void assert_not_empty(const std::string &value, const std::string &label);

void assert_not_less_than_n(int value, int n, const std::string &label);

void assert_not_greater_than_n(int value, int n, const std::string &label);

void assert_greater_than_n(int value, int n, const std::string &label);

void assert_course_in(int value, int left, int right, const std::string &label);

void assert_true(bool value, const std::string &label);