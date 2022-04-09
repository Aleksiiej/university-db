#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <numeric>
#include <fstream>
#include "Student.hpp"

class Database
{
public:
    Database() = default;

    void addStudent(const std::string name, const std::string surname, const std::string adress, const int index, const std::string PESEL, const std::string sex); // adds record
    void show() const;                                                                                                                                             // shows all records
    void printByPtr(Student *ptr) const;                                                                                                                           // print sigle records using given pointer
    void showBySurname(const std::string surname);                                                                                                                 // shows records with given surname
    void showByPESEL(const std::string PESEL);                                                                                                                     // shows record with given PESEL
    std::vector<Student *> findBySurname(std::string surname);                                                                                                     // searches for records with given surname and returns vector with pointers to these records
    Student *findByPESEL(std::string PESEL);                                                                                                                       // searches for records with given pointer and returns pointer to this record
    void sortBySurname();                                                                                                                                          // sorts records by surnames
    void sortByPESEL();                                                                                                                                            // sort records by PESEL
    void remove(int index);                                                                                                                                        // removes record with given index
    bool validatePESEL(std::string PESEL) const;                                                                                                                   // validates given PESEL
    void loadFromFile();                                                                                                                                           // load records from .txt file to vector database_
    void saveToFile();                                                                                                                                             // overwrites .txt file with records from vector database_

    Student getStudentRecord(int pos); // returns copy of record pointed by positiion in database - for testing

private:
    std::vector<Student> database_;
    std::string fileName_{"../database.txt"};
};
