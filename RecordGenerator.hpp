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
    std::unique_ptr<Person> generateRandomRecord() const;

private:
    std::string generateRandomMaleName() const;
    std::string generateRandomFemaleName() const;
    std::string generateRandomMaleSurname() const;
    std::string generateRandomFemaleSurname() const;
    std::string generateRandomAdress() const;
    int generateRandomIndex() const;
    float generateRandomSalary() const;
    std::string generateRandomPESEL(const Sex& sex) const;
    std::string generatePESELDate(std::string& tempPESEL) const;
    std::string generatePESELSex(std::string& tempPESEL, const Sex& sex) const;
    std::string generatePESELControlNumber(std::string& tempPESEL) const;
};