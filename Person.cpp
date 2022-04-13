#include "Person.hpp"

// getters
std::string Person::getName() const { return name_; }
std::string Person::getSurname() const { return surname_; }
std::string Person::getAdress() const { return adress_; }
Position Person::getPosition() const { return position_; }
int Person::getIndex() const { return -1; }
float Person::getSalary() const { return -1; }
std::string Person::getPESEL() const { return PESEL_; }
Sex Person::getSex() const { return sex_; }

// setters
void Person::setName(const std::string &name) { name_ = name; }
void Person::setSurname(const std::string &surname) { surname_ = surname; }
void Person::setAdress(const std::string &adress) { adress_ = adress; }
void Person::setPosition(const Position &position) { position_ = position; }
void Person::setIndex(const int &) {}
void Person::setSalary(const float &) {}
void Person::setPESEL(const std::string &PESEL) { PESEL_ = PESEL; }
void Person::setSex(const Sex &sex) { sex_ = sex; }
