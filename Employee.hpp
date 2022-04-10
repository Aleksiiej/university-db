#pragma once
#include "Person.hpp"

class Employee : public Person
{
    friend class Database;

public:
    Employee() = default;
    Employee(const std::string &name, const std::string &surname, const std::string &adress, const float &salary, const std::string &PESEL, const Sex &sex)
        : Person(name, surname, adress, PESEL, sex), salary_(salary)
    {
    }

    std::string getName() override;
    std::string getSurname() override;
    std::string getAdress() override;
    float getSalary();
    std::string getPESEL() override;
    Sex getSex() override;

private:
    float salary_;
};