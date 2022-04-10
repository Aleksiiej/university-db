#pragma once
#include "Person.hpp"


class Student : public Person
{
    friend class Database;

public:
    Student() = default;
    Student(const std::string &name, const std::string &surname, const std::string &adress, const int &index, const std::string &PESEL, const Sex &sex)
        : Person(name, surname, adress, PESEL, sex)
        , index_(index)
    {
    }

    std::string getName() override;
    std::string getSurname() override;
    std::string getAdress() override;
    int getIndex();
    std::string getPESEL() override;
    Sex getSex() override;

private:
    int index_;
};