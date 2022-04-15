#include "Database.hpp"

void Database::addStudent(const std::string &name, const std::string &surname, const std::string &adress, const int &index, const std::string &PESEL, const Sex &sex, const Position &position)
{
    database_.push_back(std::make_shared<Student>(Student{name, surname, adress, index, PESEL, sex, position}));
}

void Database::addEmployee(const std::string &name, const std::string &surname, const std::string &adress, const float &salary, const std::string &PESEL, const Sex &sex, const Position &position)
{
    database_.push_back(std::make_shared<Employee>(Employee{name, surname, adress, salary, PESEL, sex, position}));
}

void Database::show() const
{
    system("clear");
    std::for_each(begin(database_), end(database_), [this](const auto ptr)
                  { printByPtr(ptr); });
}

void Database::printByPtr(const std::shared_ptr<Person> ptr) const
{
    std::cout << "===================================" << std::endl;
    std::cout << "Name: " << ptr->getName() << std::endl;
    std::cout << "Surname: " << ptr->getSurname() << std::endl;
    std::cout << "Adress: " << ptr->getAdress() << std::endl;
    std::cout << "Position: " << ptr->positionPrint[ptr->getPosition()] << std::endl;
    switch (ptr->getPosition())
    {
    case Position::Student:
        std::cout << "Index: " << ptr->getIndex() << std::endl;
        break;
    case Position::Employee:
        std::cout << "Salary: " << std::fixed << std::setprecision(2) << ptr->getSalary() << std::endl;
        break;
    }
    std::cout << "PESEL: " << ptr->getPESEL() << std::endl;
    std::cout << "Sex: " << ptr->sexPrint[ptr->getSex()] << std::endl;
    std::cout << "===================================" << std::endl;
}

void Database::showBySurname(const std::string &surname) const
{
    system("clear");
    auto tempVec = findBySurname(surname);
    std::for_each(begin(tempVec), end(tempVec), [this](const auto ptr)
                  { printByPtr(ptr); });
}

void Database::showByPESEL(const std::string &PESEL) const
{
    system("clear");
    auto ptr = findByPESEL(PESEL);
    printByPtr(ptr);
}

std::vector<std::shared_ptr<Person>> Database::findBySurname(const std::string &surname) const
{
    std::vector<std::shared_ptr<Person>> tempVec;
    for (const auto &el : database_)
    {
        if (el->getSurname() == surname)
        {
            auto tempPtr = el;
            tempVec.push_back(tempPtr);
        }
    }
    return tempVec;
}

std::shared_ptr<Person> Database::findByPESEL(const std::string &PESEL) const
{

    auto tempPtr = *(std::find_if(begin(database_), end(database_), [&PESEL](const auto el)
                                  { return el->getPESEL() == PESEL; }));
    return tempPtr;
}

void Database::sortBySurname()
{
    std::sort(begin(database_), end(database_), [](auto lhs, auto rhs)
              { return lhs->getSurname() < rhs->getSurname(); });
}

void Database::sortByPESEL()
{
    std::sort(begin(database_), end(database_), [](auto lhs, auto rhs)
              { return lhs->getPESEL() < rhs->getPESEL(); });
}

void Database::sortBySalary()
{
    std::sort(begin(database_), end(database_), [](auto lhs, auto rhs)
              { return lhs->getSalary() < rhs->getSalary(); });
}

void Database::remove(const int &index)
{
    database_.erase(std::find_if(begin(database_), end(database_), [&index](const auto el)
                                 { return el->getIndex() == index; }));
}

void Database::modifySalary(const std::string &PESEL, const float &newSalary)
{
    system("clear");
    std::shared_ptr<Person> tempPtr = findByPESEL(PESEL);
    tempPtr->setSalary(newSalary);
    printByPtr(tempPtr);
    std::cout << "New salary set at value: " << std::fixed << std::setprecision(2) << tempPtr->getSalary() << std::endl;
    std::cout << "Press any button to proceed...";
    std::getchar();
    std::getchar();
}

bool Database::validatePESEL(const std::string &PESEL) const
{
    return validator_.validatePESEL(PESEL);
}

void Database::loadFromFile(const std::string &fileName)
{
    database_.clear();

    std::fstream file(fileName, std::ios::in);

    if (!file)
    {
        std::cout << "File was not opened properly \n Program will be closed" << std::endl;
        exit(0);
    }

    std::string tempName;
    std::string tempSurname;
    std::string tempAdress;
    std::string tempPositionString;
    Position tempPosition;
    std::string stringTempIndex;
    int tempIndex;
    std::string stringTempSalary;
    float tempSalary;
    std::string tempPESEL;
    std::string tempSexString;
    Sex tempSex;

    while (!file.eof())
    {
        std::getline(file, tempName);
        std::getline(file, tempSurname);
        std::getline(file, tempAdress);
        std::getline(file, tempPositionString);
        tempPosition = static_cast<Position>(stoi(tempPositionString));
        switch (tempPosition)
        {
        case Position::Student:
            std::getline(file, stringTempIndex);
            tempIndex = std::stoi(stringTempIndex);
            break;

        case Position::Employee:
            std::getline(file, stringTempSalary);
            tempSalary = std::stof(stringTempSalary);
            break;
        }
        std::getline(file, tempPESEL);
        std::getline(file, tempSexString);
        tempSex = static_cast<Sex>(stoi(tempSexString));

        switch (tempPosition)
        {
        case Position::Student:
            database_.push_back(std::make_shared<Student>(Student{tempName, tempSurname, tempAdress, tempIndex, tempPESEL, tempSex, tempPosition}));
            break;

        case Position::Employee:
            database_.push_back(std::make_shared<Employee>(Employee{tempName, tempSurname, tempAdress, tempSalary, tempPESEL, tempSex, tempPosition}));
            break;
        }
    }
}

void Database::saveToFile(const std::string &fileName)
{
    std::fstream file(fileName, std::ios::out);

    if (!file)
    {
        std::cout << "File was not opened properly \n Program will be closed" << std::endl;
        exit(0);
    }

    int counter = 0;

    for (auto ptr : database_)
    {
        file << ptr->getName() << std::endl;
        file << ptr->getSurname() << std::endl;
        file << ptr->getAdress() << std::endl;
        file << static_cast<int>(ptr->getPosition()) << std::endl;
        switch (ptr->getPosition())
        {
        case Position::Student:
            file << ptr->getIndex() << std::endl;
            break;

        case Position::Employee:
            file << ptr->getSalary() << std::endl;
            break;
        }
        file << ptr->getPESEL() << std::endl;
        file << static_cast<int>(ptr->getSex());
        counter++;
        if (counter < static_cast<int>(database_.size()))
        {
            file << std::endl;
        }
    }
}

void Database::generateData(const int &number)
{
    Sex tempSex;
    std::string tempName;
    std::string tempSurname;
    std::string tempAdress;
    Position tempPosition;
    int tempIndex;
    float tempSalary;
    std::string tempPESEL;

    for (int i = 0; i < number; i++)
    {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<> distrib(0, 1);
        int maleOrFemale = distrib(rng);      // 0 - male, 1 - female
        int studentOrEmployee = distrib(rng); // 0 - student, 1 - employee

        switch (maleOrFemale)
        {
        case 0:
            tempSex = Sex::male;
            tempName = generateRandomMaleName();
            tempSurname = generateRandomMaleSurname();
            break;
        case 1:
            tempSex = Sex::female;
            tempName = generateRandomFemaleName();
            tempSurname = generateRandomFemaleSurname();
            break;
        }
        tempAdress = generateRandomAdress();
        switch (studentOrEmployee)
        {
        case 0:
            tempPosition = Position::Student;
            tempIndex = generateRandomIndex();
            break;
        case 1:
            tempPosition = Position::Employee;
            tempSalary = generateRandomSalary();
            break;
        }
        tempPESEL = generateRandomPESEL();

        switch (studentOrEmployee)
        {
        case 0:
            database_.push_back(std::make_shared<Student>(Student{tempName, tempSurname, tempAdress, tempIndex, tempPESEL, tempSex, tempPosition}));
            break;

        case 1:
            database_.push_back(std::make_shared<Employee>(Employee{tempName, tempSurname, tempAdress, tempSalary, tempPESEL, tempSex, tempPosition}));
            break;
        }
    }
}

std::string Database::generateRandomMaleName()
{
    std::fstream file("../RandomData/maleNames.txt", std::ios::in);
    if (!file)
    {
        std::cout << "File was not opened properly \n Program will be closed" << std::endl;
        exit(0);
    }
    std::string tempName;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> distrib(0, 99);

    for (int i = 0; i < distrib(rng); i++)
    {
        file >> tempName;
    }
    return tempName;
}

std::string Database::generateRandomFemaleName()
{
    std::fstream file("../RandomData/femaleNames.txt", std::ios::in);
    if (!file)
    {
        std::cout << "File was not opened properly \n Program will be closed" << std::endl;
        exit(0);
    }
    std::string tempName;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> distrib(0, 99);

    for (int i = 0; i < distrib(rng); i++)
    {
        file >> tempName;
    }
    return tempName;
}

std::string Database::generateRandomMaleSurname()
{
    std::fstream file("../RandomData/maleSurnames.txt", std::ios::in);
    if (!file)
    {
        std::cout << "File was not opened properly \n Program will be closed" << std::endl;
        exit(0);
    }
    std::string tempSurname;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> distrib(0, 99);

    for (int i = 0; i < distrib(rng); i++)
    {
        file >> tempSurname;
    }
    return tempSurname;
}

std::string Database::generateRandomFemaleSurname()
{
    std::fstream file("../RandomData/femaleSurnames.txt", std::ios::in);
    if (!file)
    {
        std::cout << "File was not opened properly \n Program will be closed" << std::endl;
        exit(0);
    }
    std::string tempSurname;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> distrib(0, 99);

    for (int i = 0; i < distrib(rng); i++)
    {
        file >> tempSurname;
    }
    return tempSurname;
}

std::string Database::generateRandomAdress()
{
    std::fstream file("../RandomData/adresses.txt", std::ios::in);
    if (!file)
    {
        std::cout << "File was not opened properly \n Program will be closed" << std::endl;
        exit(0);
    }
    std::string tempAdress;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> distrib(0, 99);

    for (int i = 0; i < distrib(rng); i++)
    {
        std::getline(file, tempAdress);
    }
    return tempAdress;
}

int Database::generateRandomIndex()
{
    std::fstream file("../RandomData/indexes.txt", std::ios::in);
    if (!file)
    {
        std::cout << "File was not opened properly \n Program will be closed" << std::endl;
        exit(0);
    }
    std::string tempIndex;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> distrib(0, 99);

    for (int i = 0; i < distrib(rng); i++)
    {
        file >> tempIndex;
    }
    return std::stoi(tempIndex);
}

float Database::generateRandomSalary()
{
    std::fstream file("../RandomData/salaries.txt", std::ios::in);
    if (!file)
    {
        std::cout << "File was not opened properly \n Program will be closed" << std::endl;
        exit(0);
    }
    std::string tempSalary;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> distrib(0, 99);

    for (int i = 0; i < distrib(rng); i++)
    {
        file >> tempSalary;
    }
    return std::stof(tempSalary);
}

std::string Database::generateRandomPESEL()
{
    std::fstream file("../RandomData/pesels.txt", std::ios::in);
    if (!file)
    {
        std::cout << "File was not opened properly \n Program will be closed" << std::endl;
        exit(0);
    }
    std::string tempPESEL;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> distrib(0, 99);

    for (int i = 0; i < distrib(rng); i++)
    {
        file >> tempPESEL;
    }
    return tempPESEL;
}

std::shared_ptr<Person> Database::getPtrToRecord(const int &pos) const
{
    return database_.at(pos);
}
