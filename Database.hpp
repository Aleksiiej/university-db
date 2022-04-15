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

class Database
{
public:
    void addStudent(const std::string &name, const std::string &surname, const std::string &adress, const int &index, const std::string &PESEL, const Sex &sex, const Position &position) noexcept;     // adds record
    void addEmployee(const std::string &name, const std::string &surname, const std::string &adress, const float &salary, const std::string &PESEL, const Sex &sex, const Position &position) noexcept; // adds employee record
    void show() const noexcept;                                                                                                                                                                         // shows all records
    void printByPtr(const std::shared_ptr<Person> ptr) const noexcept;                                                                                                                                  // prints single records using given pointer
    void showBySurname(const std::string &surname) const noexcept;                                                                                                                                      // shows records with given surname
    void showByPESEL(const std::string &PESEL) const noexcept;                                                                                                                                          // shows record with given PESEL
    std::vector<std::shared_ptr<Person>> findBySurname(const std::string &surname) const noexcept;                                                                                                      // searches for records with given surname and returns vector with pointers to these records
    std::shared_ptr<Person> findByPESEL(const std::string &PESEL) const noexcept;                                                                                                                       // searches for records with given pointer and returns pointer to this record
    void sortBySurname() noexcept;                                                                                                                                                                      // sorts records by surnames
    void sortByPESEL() noexcept;                                                                                                                                                                        // sort records by PESEL
    void remove(const int &index) noexcept;                                                                                                                                                             // removes record with given index
    bool validatePESEL(const std::string &PESEL) const noexcept;                                                                                                                                        // validates given PESEL
    void loadFromFile(const std::string &fileName = "../database.txt") noexcept;                                                                                                                        // load records from .txt file to vector database_
    void saveToFile(const std::string &fileName = "../database.txt") noexcept;                                                                                                                          // overwrites .txt file with records from vector database_
    std::shared_ptr<Person> getPtrToRecord(const int &pos) const;                                                                                                                                       // returns pointer to record at given position

private:
    std::vector<std::shared_ptr<Person>> database_;
    PESELValidator validator_;
    std::string fileName_{"../database.txt"};
};
