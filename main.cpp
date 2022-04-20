#include <iostream>
#include "Database.hpp"
#include "Menu.hpp"

int main()
{
    Database database;
    Menu menu{database};
    menu.run();
}