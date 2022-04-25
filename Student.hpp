#pragma once
#include <iostream>
#include "Person.hpp"

class Student : public Person
{
public:
    Student(const std::string &name, const std::string &surname, const std::string &adress, const int &index, const std::string &PESEL, const Sex &sex, const Position &position)
        : Person(name, surname, adress, PESEL, sex, position), index_(index)
    {
    }

    virtual ~Student() = default;

    // getters
    std::string getName() const noexcept override;
    std::string getSurname() const noexcept override;
    std::string getAdress() const noexcept override;
    Position getPosition() const noexcept override;
    int getIndex() const noexcept override;
    float getSalary() const noexcept override;
    std::string getPESEL() const noexcept override;
    Sex getSex() const noexcept override;

    // setters
    void setSalary(const float &) noexcept override;

private:
    int index_;
};