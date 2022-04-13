#include "Student.hpp"

// getters
std::string Student::getName() const { return name_; }
std::string Student::getSurname() const { return surname_; }
std::string Student::getAdress() const { return adress_; }
Position Student::getPosition() const { return position_; }
int Student::getIndex() const { return index_; }
float Student::getSalary() const { return 0; }
std::string Student::getPESEL() const { return PESEL_; }
Sex Student::getSex() const { return sex_; }

// setters
void Student::setName(const std::string &name) { name_ = name; }
void Student::setSurname(const std::string &surname) { surname_ = surname; }
void Student::setAdress(const std::string &adress) { adress_ = adress; }
void Student::setPosition(const Position &position) { position_ = position; }
void Student::setIndex(const int &index) { index_ = index; }
void Student::setSalary(const float &) {}
void Student::setPESEL(const std::string &PESEL) { PESEL_ = PESEL; }
void Student::setSex(const Sex &sex) { sex_ = sex; }
