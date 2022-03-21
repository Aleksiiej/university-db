#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <numeric>
#include <fstream>

class Student
{
    friend class Database;

public:
    Student() = default;
    Student(const std::string &name, const std::string &surname, const std::string &adress, const int &index, const std::string &PESEL, const std::string &sex)
        : name_(name), surname_(surname), adress_(adress), index_(index), PESEL_(PESEL), sex_(sex)
    {
    }

private:
    std::string name_;
    std::string surname_;
    std::string adress_;
    int index_;
    std::string PESEL_;
    std::string sex_;
};

class Database
{
public:
    Database() = default;

    ~Database();

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
    void loadFromFile(std::string);                                                                                                                                // load records from .txt file to vector database_
    void saveToFile(std::string);                                                                                                                                  // overwrites .txt file with records from vector database_

private:
    std::vector<Student> database_;
    std::string fileName_ = "database.txt";
};
