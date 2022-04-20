#pragma once
#include "Person.hpp"

class Employee : public Person
{
public:
    Employee(const std::string &name, const std::string &surname, const std::string &adress, const float &salary, const std::string &PESEL, const Sex &sex, const Position &position)
        : Person(name, surname, adress, PESEL, sex, position), salary_(salary)
    {
    }

    virtual ~Employee() = default;

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
    void setIndex(const int &) noexcept override;
    void setSalary(const float &salary) noexcept override;
    void setPESEL(const std::string &PESEL) noexcept override;
    void setSex(const Sex &sex) noexcept override;

private:
    float salary_;
};