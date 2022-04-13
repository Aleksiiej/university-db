#include "Employee.hpp"

// getters
std::string Employee::getName() const { return name_; }
std::string Employee::getSurname() const { return surname_; }
std::string Employee::getAdress() const { return adress_; }
float Employee::getSalary() const { return salary_; }
std::string Employee::getPESEL() const { return PESEL_; }
Sex Employee::getSex() const { return sex_; }

// setters
void Employee::setName(const std::string &name) { name_ = name; }
void Employee::setSurname(const std::string &surname) { surname_ = surname; }
void Employee::setAdress(const std::string &adress) { adress_ = adress; }
void Employee::setSalary(const float &salary) { salary_ = salary; }
void Employee::setPESEL(const std::string &PESEL) { PESEL_ = PESEL; }
void Employee::setSex(const Sex &sex) { sex_ = sex; }