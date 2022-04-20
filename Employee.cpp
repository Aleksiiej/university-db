#include "Employee.hpp"

// getters
std::string Employee::getName() const noexcept { return name_; }
std::string Employee::getSurname() const noexcept { return surname_; }
std::string Employee::getAdress() const noexcept { return adress_; }
Position Employee::getPosition() const noexcept { return position_; }
int Employee::getIndex() const noexcept { return 0; }
float Employee::getSalary() const noexcept { return salary_; }
std::string Employee::getPESEL() const noexcept { return PESEL_; }
Sex Employee::getSex() const noexcept { return sex_; }

// setters
void Employee::setName(const std::string &name) noexcept { name_ = name; }
void Employee::setSurname(const std::string &surname) noexcept { surname_ = surname; }
void Employee::setAdress(const std::string &adress) noexcept { adress_ = adress; }
void Employee::setPosition(const Position &position) noexcept { position_ = position; }
void Employee::setIndex(const int &) noexcept {}
void Employee::setSalary(const float &salary) noexcept { salary_ = salary; }
void Employee::setPESEL(const std::string &PESEL) noexcept { PESEL_ = PESEL; }
void Employee::setSex(const Sex &sex) noexcept { sex_ = sex; }
