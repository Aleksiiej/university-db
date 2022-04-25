#include "Student.hpp"

// getters
std::string Student::getName() const noexcept { return name_; }
std::string Student::getSurname() const noexcept { return surname_; }
std::string Student::getAdress() const noexcept { return adress_; }
Position Student::getPosition() const noexcept { return position_; }
int Student::getIndex() const noexcept { return index_; }
float Student::getSalary() const noexcept { return 0; }
std::string Student::getPESEL() const noexcept { return PESEL_; }
Sex Student::getSex() const noexcept { return sex_; }

// setters
void Student::setSalary(const float &) noexcept {}