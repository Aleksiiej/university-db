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
    std::string getName() const override;
    std::string getSurname() const override;
    std::string getAdress() const override;
    Position getPosition() const override;
    int getIndex() const override;
    float getSalary() const override;
    std::string getPESEL() const override;
    Sex getSex() const override;

    // setters
    void setName(const std::string &name) override;
    void setSurname(const std::string &surname) override;
    void setAdress(const std::string &adress) override;
    void setPosition(const Position &position) override;
    void setIndex(const int &index);
    void setSalary(const float &) override;
    void setPESEL(const std::string &PESEL) override;
    void setSex(const Sex &sex) override;

private:
    int index_;
};