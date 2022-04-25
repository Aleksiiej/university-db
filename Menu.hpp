#pragma once
#include <iostream>
#include <memory>
#include "IDatabase.hpp"
#include "Database.hpp"
#include "Person.hpp"

class Menu
{
public:
    Menu(IDatabase &db) : ptrToDb_(&db)
    {
    }
    void run() const noexcept;
    void showMenu() const noexcept;
    void enterData() const noexcept;
    void findRecordBySurname() const noexcept;
    void findRecordByPESEL() const noexcept;
    void removeRecordByIndex() const noexcept;
    void modifySalary() const noexcept;
    void validatePESEL() const noexcept;
    void generateRandomRecords() const noexcept;

private:
    std::unique_ptr<IDatabase> ptrToDb_;
};