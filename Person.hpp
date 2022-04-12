#pragma once
#include <string>
#include <map>

enum class Sex
{
    male,
    female
};

class Person
{
    friend class Database;

public:
    Person(std::string name, std::string surname, std::string adress, std::string PESEL, Sex sex)
        : name_(name), surname_(surname), adress_(adress), PESEL_(PESEL), sex_(sex)
    {
    }

    virtual std::string getName();
    virtual std::string getSurname();
    virtual std::string getAdress();
    virtual int getIndex() { return -1; }
    virtual float getSalary() { return -1; }
    virtual std::string getPESEL();
    virtual Sex getSex();

    int classId;

protected:
    std::string name_;
    std::string surname_;
    std::string adress_;
    std::string PESEL_;
    Sex sex_;

    std::map<Sex, std::string> sexPrint{{Sex::male, "male"}, {Sex::female, "female"}};
};