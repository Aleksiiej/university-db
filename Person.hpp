#pragma once
#include <string>

enum class Sex { male, female };

class Person
{
    std::string name_;
    std::string surname_;
    std::string adress_;
    std::string PESEL_;
    Sex sex_;

    virtual std::string getName();
    virtual std::string getSurname();
    virtual std::string getAdress();
    virtual std::string getPESEL();
    virtual Sex getSex();
};