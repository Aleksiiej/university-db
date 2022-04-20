#include <iostream>
#include "Database.hpp"
#include "Menu.hpp"

int main()
{
    Database database;
    Menu menu{database};

    database.addStudent("Jan", "Nowak", "Gniezno, Jemiolowa 16", 217025, "93121312345", Sex::male, Position::Student);
    database.addStudent("Aleksandra", "Nowakowska", "Bydgoszcz, Zwyczajna 5", 126574, "93040523495", Sex::female, Position::Student);
    database.addStudent("Piotr", "Kowalski", "Warszawa, Przykladowa 20", 223412, "89275430298", Sex::male, Position::Student);
    database.addEmployee("Andrzej", "Niezbedny", "Sopot, Powstancow Slaskich 10", 4600.50, "78032559472", Sex::male, Position::Employee);
    database.addEmployee("Renata", "Zaradna", "Ustrzyki, Powstancow Malopolskich 133", 4340.00, "73031054872", Sex::female, Position::Employee);
    // database.saveToFile();
    // database.loadFromFile();
    // database.show();
    // database.modifySalary("78032559472");
    // database.show();
    // database.sortBySalary();
    // database.show();
    // database.generateData(4);
    // std::cout << database.generateRandomMaleName() << std::endl;
    // std::cout << database.generateRandomFemaleName() << std::endl;
    // std::cout << database.generateRandomMaleSurname() << std::endl;
    // std::cout << database.generateRandomFemaleSurname() << std::endl;
    // std::cout << database.generateRandomAdress() << std::endl;
    // std::cout << database.generateRandomIndex() << std::endl;
    // std::cout << database.generateRandomSalary() << std::endl;
    // std::cout << database.generateRandomPESEL() << std::endl;
    // database.show();
    // database.saveToFile();
    // database.validatePESEL("40122340392");
    menu.run();
}