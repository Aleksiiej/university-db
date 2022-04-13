#pragma once
#include "Person.hpp"

class Employee : public Person
{
public:
    Employee(const std::string& name, const std::string& surname, const std::string& adress, const float& salary, const std::string& PESEL, const Sex& sex)
        : Person(name, surname, adress, PESEL, sex), salary_(salary)
    {
    }

    // getters
    std::string getName() const override;
    std::string getSurname() const override;
    std::string getAdress() const override;
    float getSalary() const override;
    std::string getPESEL() const override;
    Sex getSex() const override;

    // setters
    void setName(const std::string &name) override;
    void setSurname(const std::string &surname) override;
    void setAdress(const std::string &adress) override;
    void setSalary(const float &salary) override;
    void setPESEL(const std::string &PESEL) override;
    void setSex(const Sex &sex) override;

    int classId{2};

private:
    float salary_;
};