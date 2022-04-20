#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <iomanip>
#include "Person.hpp"
#include "Student.hpp"
#include "Employee.hpp"
#include "PESELValidator.hpp"
#include "RecordGenerator.hpp"

class Database
{
public:
    void addStudent(const std::string &name, const std::string &surname, const std::string &adress, const int &index, const std::string &PESEL, const Sex &sex, const Position &position);     // adds record
    void addEmployee(const std::string &name, const std::string &surname, const std::string &adress, const float &salary, const std::string &PESEL, const Sex &sex, const Position &position); // adds employee record
    void show() const;                                                                                                                                                                         // shows all records
    void printByPtr(const std::shared_ptr<Person> ptr) const;                                                                                                                                  // prints single records using given pointer
    void showBySurname(const std::string &surname) const;                                                                                                                                      // shows records with given surname
    void showByPESEL(const std::string &PESEL) const;                                                                                                                                          // shows record with given PESEL
    std::vector<std::shared_ptr<Person>> findBySurname(const std::string &surname) const;                                                                                                      // searches for records with given surname and returns vector with pointers to these records
    std::shared_ptr<Person> findByPESEL(const std::string &PESEL) const;                                                                                                                       // searches for records with given pointer and returns pointer to this record
    void sortBySurname();                                                                                                                                                                      // sorts records by surnames
    void sortByPESEL();
    void sortBySalary();                                                 // sorts records by PESEL
    void removeByIndex(const int &index);                                       // removes record with given index
    void modifySalary(const std::string &PESEL, const float &newSalary); // modyfies salary in record with given PESEL
    bool validatePESEL(const std::string &PESEL) const;                  // validates given PESEL
    void loadFromFile(const std::string &fileName = "../database.txt");  // load records from .txt file to vector database_
    void saveToFile(const std::string &fileName = "../database.txt");    // overwrites .txt file with records from vector database_
    void generateData(const int &n);                                     // generates n random records
    std::shared_ptr<Person> getPtrToRecord(const int &pos) const;        // returns pointer to record at given position

private:
    std::vector<std::shared_ptr<Person>> database_;
    std::string fileName_{"../database.txt"};
};
