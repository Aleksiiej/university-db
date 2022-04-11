#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <numeric>
#include <fstream>
#include "Person.hpp"
#include "Student.hpp"
#include "Employee.hpp"

class Database
{
public:
    Database() = default;

    void addStudent(const std::string name, const std::string surname, const std::string adress, const int index, const std::string PESEL, const Sex sex); // adds record
    void addEmployee(const std::string name, const std::string surname, const std::string adress, const float salary, const std::string PESEL, const Sex sex); //adds employee record
    void show();                                                                                                                                             // shows all records
    void printByPtr(Person *ptr) const;                                                                                                                           // print sigle records using given pointer
    void showBySurname(const std::string surname);                                                                                                                 // shows records with given surname
    void showByPESEL(const std::string PESEL);                                                                                                                     // shows record with given PESEL
    std::vector<Person *> findBySurname(std::string surname);                                                                                                     // searches for records with given surname and returns vector with pointers to these records
    Person *findByPESEL(std::string PESEL);                                                                                                                       // searches for records with given pointer and returns pointer to this record
    void sortBySurname();                                                                                                                                          // sorts records by surnames
    void sortByPESEL();                                                                                                                                            // sort records by PESEL
    void remove(int index);                                                                                                                                        // removes record with given index
    bool validatePESEL(std::string PESEL) const;                                                                                                                   // validates given PESEL
    void loadFromFile();                                                                                                                                           // load records from .txt file to vector database_
    void saveToFile();                                                                                                                                             // overwrites .txt file with records from vector database_

    Person* getStudentRecord(int pos); // returns copy of student record pointed by positiion in database - for testing
    Person* getEmployeeRecord(int pos); // returns copy of employee record pointed by positiion in database - for testing

private:
    std::vector<Person> database_;
    std::string fileName_{"../database.txt"};
};
