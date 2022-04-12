#pragma once
#include "Person.hpp"

class Student : public Person
{
    friend class Database;

public:
    Student(std::string name, std::string surname, std::string adress, int index, std::string PESEL, Sex sex)
        : Person(name, surname, adress, PESEL, sex), index_(index)
    {
    }

    std::string getName() override;
    std::string getSurname() override;
    std::string getAdress() override;
    int getIndex();
    std::string getPESEL() override;
    Sex getSex() override;

    int classId{1};

private:
    int index_;
};