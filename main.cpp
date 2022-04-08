#include <iostream>
#include "Database.hpp"

int main()
{
    Database database;
    //database.addStudent("Jan", "Nowak", "Gniezno, Jemiolowa 16", 217025, "95061243576", "male");
    //database.addStudent("Aleksandra", "Nowakowska", "Bydgoszcz, Zwyczajna 5", 126574, "93040523495", "female");
    //database.show();
    //database.showBySurname("Nowakowska");
    //database.showByPESEL("93040523495");
    //database.sortBySurname();
    //database.show();
    //database.remove(217025);
    //database.show();
    //database.validatePESEL("95082910213");
    database.loadFromFile("database.txt");
    //database.saveToFile("database.txt");
    database.show();
}