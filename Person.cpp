#include "Person.hpp"

// getters
std::string Person::getName() const noexcept { return name_; }
std::string Person::getSurname() const noexcept { return surname_; }
std::string Person::getAdress() const noexcept { return adress_; }
Position Person::getPosition() const noexcept { return position_; }
int Person::getIndex() const noexcept { return -1; }
float Person::getSalary() const noexcept { return -1; }
std::string Person::getPESEL() const noexcept { return PESEL_; }
Sex Person::getSex() const noexcept { return sex_; }

// setters
void Person::setName(const std::string &name) noexcept { name_ = name; }
void Person::setSurname(const std::string &surname) noexcept { surname_ = surname; }
void Person::setAdress(const std::string &adress) noexcept { adress_ = adress; }
void Person::setPosition(const Position &position) noexcept { position_ = position; }
void Person::setIndex(const int &) noexcept {}
void Person::setSalary(const float &) noexcept {}
void Person::setPESEL(const std::string &PESEL) noexcept { PESEL_ = PESEL; }
void Person::setSex(const Sex &sex) noexcept { sex_ = sex; }
