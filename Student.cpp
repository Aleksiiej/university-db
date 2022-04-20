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
void Student::setName(const std::string &name) noexcept { name_ = name; }
void Student::setSurname(const std::string &surname) noexcept { surname_ = surname; }
void Student::setAdress(const std::string &adress) noexcept { adress_ = adress; }
void Student::setPosition(const Position &position) noexcept { position_ = position; }
void Student::setIndex(const int &index) noexcept { index_ = index; }
void Student::setSalary(const float &) noexcept {}
void Student::setPESEL(const std::string &PESEL) noexcept { PESEL_ = PESEL; }
void Student::setSex(const Sex &sex) noexcept { sex_ = sex; }
