#pragma once
#include "Person.hpp"

class Employee : public Person
{
    friend class Database;

public:
    Employee(std::string name, std::string surname, std::string adress, float salary, std::string PESEL, Sex sex)
        : Person(name, surname, adress, PESEL, sex), salary_(salary)
    {
    }

    std::string getName() override;
    std::string getSurname() override;
    std::string getAdress() override;
    float getSalary();
    std::string getPESEL() override;
    Sex getSex() override;

    int classId{2};

private:
    float salary_;
};