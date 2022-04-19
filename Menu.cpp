#include "Menu.hpp"

void Menu::setPtrToDatabase(std::unique_ptr<Database> ptrToDb) noexcept
{
    ptrToDb_ = std::move(ptrToDb);
}

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
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            break;

        case 8:
            break;

        case 9:
            break;

        case 10:
            break;

        case 11:
            break;

        case 12:
            break;

        case 13:
            break;

        case 14:
            exit(0);

        default:
            break;
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
    int position;
    int index;
    float salary;
    std::string PESEL;
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

    std::cout << "Enter position: type 0 if student, 1 if employee: ";
    std::cin >> position;
    if (position == 0)
    {
        std::cout << "Enter index: ";
        std::cin >> index;
    }
    else if (position == 1)
    {
        std::cout << "Enter salary: ";
        std::cin >> index;
    }

    std::cout << "Enter PESEL: ";
    std::cin >> PESEL;

    std::cout << "Enter sex: type 0 if male, 1 if female: ";
    std::cin >> sex;

    switch (position)
    {
    case 0:
        ptrToDb_->addStudent(name, surname, adress, index, PESEL, static_cast<Sex>(sex), Position::Student);
        break;

    case 1:
        ptrToDb_->addEmployee(name, surname, adress, salary, PESEL, static_cast<Sex>(sex), Position::Student);
        break;
    }
}