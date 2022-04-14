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
    std::sort(begin(database_), end(database_), [](auto a, auto b)
              { return a->getSurname() < b->getSurname(); });
}

void Database::sortByPESEL()
{
    std::sort(begin(database_), end(database_), [](auto a, auto b)
              { return a->getPESEL() < b->getPESEL(); });
}

void Database::remove(const int &index)
{
    database_.erase(std::find_if(begin(database_), end(database_), [&index](const auto el)
                                 { return el->getIndex() == index; }));
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

    int counter = 1;

    while (!file.eof())
    {
        if (counter % 7 == 1)
        {
            std::getline(file, tempName);
            counter++;
        }
        if (counter % 7 == 2)
        {
            std::getline(file, tempSurname);
            counter++;
        }
        if (counter % 7 == 3)
        {
            std::getline(file, tempAdress);
            counter++;
        }
        if (counter % 7 == 4)
        {
            std::getline(file, tempPositionString);
            tempPosition = static_cast<Position>(stoi(tempPositionString));
            counter++;
        }
        if (counter % 7 == 5 && tempPosition == Position::Student)
        {
            std::getline(file, stringTempIndex);
            tempIndex = std::stoi(stringTempIndex);
            counter++;
        }
        if (counter % 7 == 5 && tempPosition == Position::Employee)
        {
            std::getline(file, stringTempSalary);
            tempSalary = std::stof(stringTempSalary);
            counter++;
        }
        if (counter % 7 == 6)
        {
            std::getline(file, tempPESEL);
            counter++;
        }
        if (counter % 7 == 0)
        {
            std::getline(file, tempSexString);
            tempSex = static_cast<Sex>(stoi(tempSexString));
            counter++;
        }

        if (tempPosition == Position::Student)
        {
            database_.push_back(std::make_shared<Student>(Student{tempName, tempSurname, tempAdress, tempIndex, tempPESEL, tempSex, tempPosition}));
        }
        else if (tempPosition == Position::Employee)
        {
            database_.push_back(std::make_shared<Employee>(Employee{tempName, tempSurname, tempAdress, tempSalary, tempPESEL, tempSex, tempPosition}));
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
        if (ptr->getPosition() == Position::Student)
        {
            file << ptr->getIndex() << std::endl;
        }
        else if (ptr->getPosition() == Position::Employee)
        {
            file << ptr->getSalary() << std::endl;
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

std::shared_ptr<Person> Database::getPtrToRecord(const int &pos) const
{
    return database_.at(pos);
}
