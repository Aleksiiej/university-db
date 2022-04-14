#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class PESELValidator
{
    bool validatePESEL(const std::string &PESEL) const;
    bool validatePESELSize(const std::string &PESEL) const;
    bool validatePESELDate(const std::string &PESEL) const;
    bool validateControlNumber(const std::string &PESEL) const;
};