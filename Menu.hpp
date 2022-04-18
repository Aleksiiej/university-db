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
    void run() const noexcept;
    void showMenu() const noexcept;
    void enterData() const noexcept;
    void setPtrToDatabase(std::unique_ptr<Database> ptrToDb) noexcept;

private:
    std::unique_ptr<Database> ptrToDb_;
};