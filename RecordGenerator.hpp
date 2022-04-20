#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <random>
#include <algorithm>
#include "Person.hpp"
#include "Student.hpp"
#include "Employee.hpp"

constexpr int minIndex = 20000;
constexpr int maxIndex = 39999;
constexpr float minSalary = 2000.00;
constexpr float maxSalary = 6000.00;
constexpr int minYearIfBirth = 1900;
constexpr int maxYearOfBirth = 1999;

class RecordGenerator
{
public:
    std::unique_ptr<Person> generateRandomRecord() const noexcept;

private:
    std::string generateRandomMaleName() const noexcept;
    std::string generateRandomFemaleName() const noexcept;
    std::string generateRandomMaleSurname() const noexcept;
    std::string generateRandomFemaleSurname() const noexcept;
    std::string generateRandomAdress() const noexcept;
    int generateRandomIndex() const noexcept;
    float generateRandomSalary() const noexcept;
    std::string generateRandomPESEL(const Sex& sex) const noexcept;
    std::string generatePESELDate(std::string& tempPESEL) const noexcept;
    std::string generatePESELSex(std::string& tempPESEL, const Sex& sex) const noexcept;
    std::string generatePESELControlNumber(std::string& tempPESEL) const noexcept;
};