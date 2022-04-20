#pragma once
#include <iostream>
#include <memory>
#include "Database.hpp"
#include "Person.hpp"

class Menu
{
public:
    Menu() = default;
    Menu(Database &db) : ptrToDb_(&db)
    {
    }
    void run() noexcept;
    void showMenu() const noexcept;
    void enterData() const noexcept;
    void findRecordBySurname() const noexcept;
    void findRecordByPESEL() const noexcept;
    void sortRecordsBySurname() const noexcept;
    void sortRecordsByPESEL() const noexcept;
    void setPtrToDatabase(std::unique_ptr<Database> ptrToDb) noexcept;

private:
    std::unique_ptr<Database> ptrToDb_;
};