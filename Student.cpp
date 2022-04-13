#include "Student.hpp"

// getters
std::string Student::getName() const { return name_; }
std::string Student::getSurname() const { return surname_; }
std::string Student::getAdress() const { return adress_; }
int Student::getIndex() const { return index_; }
std::string Student::getPESEL() const { return PESEL_; }
Sex Student::getSex() const { return sex_; }

// setters
void Student::setName(const std::string& name) { name_ = name; }
void Student::setSurname(const std::string& surname) { surname_ = surname; }
void Student::setAdress(const std::string& adress) { adress_ = adress; }
void Student::setIndex(const int& index) { index_ = index; }
void Student::setPESEL(const std::string& PESEL) { PESEL_ = PESEL; }
void Student::setSex(const Sex& sex) { sex_ = sex; }