#pragma once
#include "gmock/gmock.h"
#include "../IDatabase.hpp"

class DatabaseMock : public IDatabase
{
public:
    MOCK_METHOD(void, addStudent, (const std::string &name, const std::string &surname, const std::string &adress, const int &index, const std::string &PESEL, const Sex &sex, const Position &position), (noexcept, override));
    MOCK_METHOD(void, addEmployee, (const std::string &name, const std::string &surname, const std::string &adress, const float &salary, const std::string &PESEL, const Sex &sex, const Position &position), (noexcept, override));
    MOCK_METHOD(void, show, (), (const, noexcept, override));
    MOCK_METHOD(void, printByPtr, (const std::shared_ptr<Person> ptr), (const, noexcept, override));
    MOCK_METHOD(void, showBySurname, (const std::string &surname), (const, noexcept, override));
    MOCK_METHOD(void, showByPESEL, (const std::string &PESEL), (const, noexcept, override));
    MOCK_METHOD(std::vector<std::shared_ptr<Person>>, findBySurname, (const std::string &surname), (const, noexcept, override));
    MOCK_METHOD(std::shared_ptr<Person>, findByPESEL, (const std::string &PESEL), (const, noexcept, override));
    MOCK_METHOD(void, sortBySurname, (), (noexcept, override));
    MOCK_METHOD(void, sortByPESEL, (), (noexcept, override));
    MOCK_METHOD(void, sortBySalary, (), (noexcept, override));
    MOCK_METHOD(bool, removeByIndex, (const int &index), (noexcept, override));
    MOCK_METHOD(bool, modifySalary, (const std::string &PESEL, const float &newSalary), (noexcept, override));
    MOCK_METHOD(bool, validatePESEL, (const std::string &PESEL), (const, noexcept, override));
    MOCK_METHOD(void, loadFromFile, (const std::string &fileName), (noexcept, override));
    MOCK_METHOD(void, saveToFile, (const std::string &fileName), (noexcept, override));
    MOCK_METHOD(void, generateData, (const int &n), (noexcept, override));
    MOCK_METHOD(std::shared_ptr<Person>, getPtrToRecord, (const int &pos), (const, noexcept, override));
};