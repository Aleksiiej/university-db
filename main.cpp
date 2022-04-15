#include <iostream>
#include "Database.hpp"

int main()
{
    Database database;
    database.addStudent("Jan", "Nowak", "Gniezno, Jemiolowa 16", 217025, "93121312345", Sex::male, Position::Student);
    database.addStudent("Aleksandra", "Nowakowska", "Bydgoszcz, Zwyczajna 5", 126574, "93040523495", Sex::female, Position::Student);
    database.addStudent("Piotr", "Kowalski", "Warszawa, Przykladowa 20", 223412, "89275430298", Sex::male, Position::Student);
    database.addEmployee("Andrzej", "Niezbedny", "Sopot, Powstancow Slaskich 10", 4600.50, "78032559472", Sex::male, Position::Employee);
    // database.saveToFile();
    // database.loadFromFile();
    database.show();
    // database.modifySalary("78032559472");
    // database.show();
}