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
public:
    Person(const std::string &name, const std::string &surname, const std::string &adress, const std::string &PESEL, const Sex &sex)
        : name_(name), surname_(surname), adress_(adress), PESEL_(PESEL), sex_(sex)
    {
    }

    // getters
    virtual std::string getName() const;
    virtual std::string getSurname() const;
    virtual std::string getAdress() const;
    virtual int getIndex() const;
    virtual float getSalary() const;
    virtual std::string getPESEL() const;
    virtual Sex getSex() const;

    // setters
    virtual void setName(const std::string &name);
    virtual void setSurname(const std::string &surname);
    virtual void setAdress(const std::string &adress);
    virtual void setIndex(const int &);
    virtual void setSalary(const float &);
    virtual void setPESEL(const std::string &PESEL);
    virtual void setSex(const Sex &sex);

    int classId;
    std::map<Sex, std::string> sexPrint{{Sex::male, "male"}, {Sex::female, "female"}};

protected:
    std::string name_;
    std::string surname_;
    std::string adress_;
    std::string PESEL_;
    Sex sex_;
};