#pragma once
#include "Person.hpp"

class Student : public Person
{
public:
    Student(const std::string& name, const std::string& surname, const std::string& adress, const int& index, const std::string& PESEL, const Sex& sex)
        : Person(name, surname, adress, PESEL, sex), index_(index)
    {
    }

    //getters
    std::string getName() const override;
    std::string getSurname() const override;
    std::string getAdress() const override;
    int getIndex() const override;
    std::string getPESEL() const override;
    Sex getSex() const override;

    //setters
    void setName(const std::string& name) override;
    void setSurname(const std::string& surname) override;
    void setAdress(const std::string& adress) override;
    void setIndex(const int& index) override;
    void setPESEL(const std::string& PESEL) override;
    void setSex(const Sex& sex) override;

    int classId{1};

private:
    int index_;
};