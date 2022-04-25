#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <iomanip>
#include "IDatabase.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Employee.hpp"
#include "PESELValidator.hpp"
#include "RecordGenerator.hpp"

class Database : public IDatabase
{
public:
    void addStudent(const std::string &name, const std::string &surname, const std::string &adress, const int &index, const std::string &PESEL, const Sex &sex, const Position &position) noexcept;
    void addEmployee(const std::string &name, const std::string &surname, const std::string &adress, const float &salary, const std::string &PESEL, const Sex &sex, const Position &position) noexcept;
    void show() const noexcept;
    void printByPtr(const std::shared_ptr<Person> ptr) const noexcept;
    void showBySurname(const std::string &surname) const noexcept;
    void showByPESEL(const std::string &PESEL) const noexcept;
    std::vector<std::shared_ptr<Person>> findBySurname(const std::string &surname) const noexcept;
    std::shared_ptr<Person> findByPESEL(const std::string &PESEL) const noexcept;
    void sortBySurname() noexcept;
    void sortByPESEL() noexcept;
    void sortBySalary() noexcept;
    bool removeByIndex(const int &index) noexcept;
    bool modifySalary(const std::string &PESEL, const float &newSalary) noexcept;
    bool validatePESEL(const std::string &PESEL) const noexcept;
    void loadFromFile(const std::string &fileName = "../database.txt") noexcept;
    void saveToFile(const std::string &fileName = "../database.txt") noexcept;
    void generateData(const int &n) noexcept;
    std::shared_ptr<Person> getPtrToRecord(const int &pos) const noexcept;

private:
    std::vector<std::shared_ptr<Person>> database_;
    std::string fileName_{"../database.txt"};
};
