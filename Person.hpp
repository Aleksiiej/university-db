#pragma once
#include <string>
#include <map>

enum class Sex
{
    male,
    female
};

enum class Position
{
    Student,
    Employee
};

class Person
{
public:
    Person(const std::string &name, const std::string &surname, const std::string &adress, const std::string &PESEL, const Sex &sex, const Position &position)
        : name_(name), surname_(surname), adress_(adress), PESEL_(PESEL), sex_(sex), position_(position)
    {
    }

    virtual ~Person() = default;

    // getters
    virtual std::string getName() const noexcept;
    virtual std::string getSurname() const noexcept;
    virtual std::string getAdress() const noexcept;
    virtual Position getPosition() const noexcept;
    virtual int getIndex() const noexcept;
    virtual float getSalary() const noexcept;
    virtual std::string getPESEL() const noexcept;
    virtual Sex getSex() const noexcept;

    // setters
    virtual void setSalary(const float &salary) noexcept;

    std::map<Sex, std::string> sexPrint{{Sex::male, "male"}, {Sex::female, "female"}};
    std::map<Position, std::string> positionPrint{{Position::Student, "Student"}, {Position::Employee, "Employee"}};

protected:
    std::string name_;
    std::string surname_;
    std::string adress_;
    std::string PESEL_;
    Sex sex_;
    Position position_;
};