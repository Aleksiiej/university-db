#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <random>
#include "Person.hpp"
#include "Student.hpp"
#include "Employee.hpp"

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
    std::string generateRandomPESEL() const;
};