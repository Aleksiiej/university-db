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

    void addStudent(std::string name, std::string surname, std::string adress, int index, std::string PESEL, Sex sex, Position position);    // adds record
    void addEmployee(std::string name, std::string surname, std::string adress, float salary, std::string PESEL, Sex sex, Position osition); // adds employee record
    void show();                                                                                                                             // shows all records
    void printByPtr(std::shared_ptr<Person> ptr) const;                                                                                      // print sigle records using given pointer
    void showBySurname(const std::string surname);                                                                                           // shows records with given surname
    void showByPESEL(const std::string PESEL);                                                                                               // shows record with given PESEL
    std::vector<std::shared_ptr<Person>> findBySurname(std::string surname);                                                                 // searches for records with given surname and returns vector with pointers to these records
    std::shared_ptr<Person> findByPESEL(std::string PESEL);                                                                                  // searches for records with given pointer and returns pointer to this record
    void sortBySurname();                                                                                                                    // sorts records by surnames
    void sortByPESEL();                                                                                                                      // sort records by PESEL
    void remove(int index);                                                                                                                  // removes record with given index
    bool validatePESEL(std::string PESEL) const;                                                                                             // validates given PESEL
    void loadFromFile();                                                                                                                     // load records from .txt file to vector database_
    void saveToFile();                                                                                                                       // overwrites .txt file with records from vector database_

    std::shared_ptr<Person> getPtrToRecord(int pos); // returns copy of record pointed by positiion in database - for testing


    std::vector<std::shared_ptr<Person>> database_;
    std::string fileName_{"../database.txt"};
};
