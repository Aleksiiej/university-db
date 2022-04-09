#pragma once
#include <string>

class Student
{
    friend class Database;

public:
    Student() = default;
    Student(const std::string &name, const std::string &surname, const std::string &adress, const int &index, const std::string &PESEL, const std::string &sex)
        : name_(name), surname_(surname), adress_(adress), index_(index), PESEL_(PESEL), sex_(sex)
    {
    }

    std::string getName();
    std::string getSurname();
    std::string getAdress();
    int getIndex();
    std::string getPESEL();
    std::string getSex();

private:
    std::string name_;
    std::string surname_;
    std::string adress_;
    int index_;
    std::string PESEL_;
    std::string sex_;
};