#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Person.hpp"

class IDatabase
{
public:
    virtual void addStudent(const std::string &name, const std::string &surname, const std::string &adress, const int &index, const std::string &PESEL, const Sex &sex, const Position &position) noexcept = 0;
    virtual void addEmployee(const std::string &name, const std::string &surname, const std::string &adress, const float &salary, const std::string &PESEL, const Sex &sex, const Position &position) noexcept = 0;
    virtual void show() const noexcept = 0;
    virtual void printByPtr(const std::shared_ptr<Person> ptr) const noexcept = 0;
    virtual void showBySurname(const std::string &surname) const noexcept = 0;
    virtual void showByPESEL(const std::string &PESEL) const noexcept = 0;
    virtual std::vector<std::shared_ptr<Person>> findBySurname(const std::string &surname) const noexcept = 0;
    virtual std::shared_ptr<Person> findByPESEL(const std::string &PESEL) const noexcept = 0;
    virtual void sortBySurname() noexcept = 0;
    virtual void sortByPESEL() noexcept = 0;
    virtual void sortBySalary() noexcept = 0;
    virtual bool removeByIndex(const int &index) noexcept = 0;
    virtual bool modifySalary(const std::string &PESEL, const float &newSalary) noexcept = 0;
    virtual bool validatePESEL(const std::string &PESEL) const noexcept = 0;
    virtual void loadFromFile(const std::string &fileName = "../database.txt") noexcept = 0;
    virtual void saveToFile(const std::string &fileName = "../database.txt") noexcept = 0;
    virtual void generateData(const int &n) noexcept = 0;
    virtual std::shared_ptr<Person> getPtrToRecord(const int &pos) const noexcept = 0;
};