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
void Employee::setSalary(const float &salary) noexcept { salary_ = salary; }