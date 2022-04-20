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
    void setName(const std::string &name) noexcept override;
    void setSurname(const std::string &surname) noexcept override;
    void setAdress(const std::string &adress) noexcept override;
    void setPosition(const Position &position) noexcept override;
    void setIndex(const int &index) noexcept override;
    void setSalary(const float &) noexcept override;
    void setPESEL(const std::string &PESEL) noexcept override;
    void setSex(const Sex &sex) noexcept override;

private:
    int index_;
};