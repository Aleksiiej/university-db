#include "Menu.hpp"

void Menu::run() const noexcept
{
    int choose;

    while (true)
    {
        showMenu();
        std::cin >> choose;

        switch (choose)
        {
        case 1:
            enterData();
            break;

        case 2:
            ptrToDb_->show();
            std::cout << "Press enter to proceed...";
            std::getchar();
            break;

        case 3:
            findRecordBySurname();
            std::cout << "Press enter to proceed...";
            break;

        case 4:
            findRecordByPESEL();
            std::cout << "Press enter to proceed...";
            break;

        case 5:
            ptrToDb_->sortBySurname();
            break;

        case 6:
            ptrToDb_->sortByPESEL();
            break;

        case 7:
            ptrToDb_->sortBySalary();
            break;

        case 8:
            removeRecordByIndex();
            break;

        case 9:
            modifySalary();
            break;

        case 10:
            validatePESEL();
            break;

        case 11:
            ptrToDb_->loadFromFile();
            break;

        case 12:
            ptrToDb_->saveToFile();
            break;

        case 13:
            generateRandomRecords();
            break;

        case 14:
            exit(0);

        default:;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}

void Menu::showMenu() const noexcept
{
    system("clear");
    std::cout << "Avalaible options:" << std::endl;
    std::cout << "1. Add record" << std::endl;
    std::cout << "2. Show all records" << std::endl;
    std::cout << "3. Find record by surname" << std::endl;
    std::cout << "4. Find record by PESEL" << std::endl;
    std::cout << "5. Sort records by surname" << std::endl;
    std::cout << "6. Sort records by PESEL" << std::endl;
    std::cout << "7. Sort employee records by salaries" << std::endl;
    std::cout << "8. Remove student record by index" << std::endl;
    std::cout << "9. Modify salary in employee record" << std::endl;
    std::cout << "10. Validate PESEL" << std::endl;
    std::cout << "11. Load database from file " << std::endl;
    std::cout << "12. Save database to file" << std::endl;
    std::cout << "13. Generate random records" << std::endl;
    std::cout << "14. Exit" << std::endl;
    std::cout << "To navigate options, enter number and press Enter: ";
}

void Menu::enterData() const noexcept
{
    std::string name;
    std::string surname;
    std::string adress;
    std::string tempPosition;
    int position;
    int index;
    float salary;
    std::string PESEL;
    std::string tempSex;
    int sex;

    system("clear");

    std::cin.clear();
    std::cin.ignore(1000, '\n');

    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    std::cout << "Enter surname: ";
    std::getline(std::cin, surname);

    std::cout << "Enter adress: ";
    std::getline(std::cin, adress);

    std::cout << "Enter position: type 0 if student, any other button if employee: ";
    std::getline(std::cin, tempPosition);
    if (tempPosition == "0")
    {
        position = 0;
        std::cout << "Enter index: ";
        std::cin >> index;
    }
    else
    {
        position = 1;
        std::cout << "Enter salary: ";
        std::cin >> salary;
    }

    std::cout << "Enter PESEL: ";
    std::cin >> PESEL;
    while (ptrToDb_->validatePESEL(PESEL) == false)
    {
        std::cout << "Enter correct PESEL number: ";
        std::cin >> PESEL;
    }

    std::cout << "Enter sex: type 0 if male, any other button if female: ";
    std::cin >> tempSex;
    if (tempSex == "0")
    {
        sex = 0;
    }
    else
    {
        sex = 1;
    }

    switch (position)
    {
    case 0:
        ptrToDb_->addStudent(name, surname, adress, index, PESEL, static_cast<Sex>(sex), Position::Student);
        break;

    case 1:
        ptrToDb_->addEmployee(name, surname, adress, salary, PESEL, static_cast<Sex>(sex), Position::Employee);
        break;
    }
}

void Menu::findRecordBySurname() const noexcept
{
    std::cout << "Enter surname: ";
    std::string tempSurname;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, tempSurname);
    ptrToDb_->showBySurname(tempSurname);
}

void Menu::findRecordByPESEL() const noexcept
{
    std::cout << "Enter PESEL: ";
    std::string tempPESEL;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, tempPESEL);
    ptrToDb_->showByPESEL(tempPESEL);
}

void Menu::removeRecordByIndex() const noexcept
{
    std::cout << "Enter index: ";
    int index;
    std::cin >> index;
    bool value = ptrToDb_->removeByIndex(index);
    if (value == false)
    {
        std::cout << "Press enter to proceed...";
        std::getchar();
    }
}

void Menu::modifySalary() const noexcept
{
    std::cout << "Enter PESEL: ";
    std::string tempPESEL;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, tempPESEL);
    std::cout << "Enter new salary(0-10000): ";
    int tempSalary;
    std::cin >> tempSalary;

    bool value = ptrToDb_->modifySalary(tempPESEL, tempSalary);
    if (value == true)
    {
        system("clear");
        std::cout << "New salary set at value: " << std::fixed << std::setprecision(2) << tempSalary << std::endl;
        std::cout << "Press enter to proceed...";
        std::getchar();
    }
    else if (value == false)
    {
        system("clear");
        std::cout << "No employee records with given PESEL found" << std::endl;
        std::cout << "Press enter to proceed...";
        std::getchar();
    }
}

void Menu::validatePESEL() const noexcept
{
    std::cout << "Enter PESEL: ";
    std::string tempPESEL;
    std::cin >> tempPESEL;
    ptrToDb_->validatePESEL(tempPESEL);
    std::cout << "Press enter to proceed...";
    std::getchar();
}

void Menu::generateRandomRecords() const noexcept
{
    std::cout << "Enter how many records have to be generated(0-100): ";
    int tempNumber;
    std::cin >> tempNumber;
    if (tempNumber >= 0 || tempNumber <= 100)
    {
        ptrToDb_->generateData(tempNumber);
    }
}
