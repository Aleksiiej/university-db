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
void Person::setSalary(const float &) noexcept {}