#include "Database.hpp"

void Database::addStudent(const std::string &name, const std::string &surname, const std::string &adress, const int &index, const std::string &PESEL, const Sex &sex, const Position &position) noexcept
{
    database_.push_back(std::make_shared<Student>(Student{name, surname, adress, index, PESEL, sex, position}));
}

void Database::addEmployee(const std::string &name, const std::string &surname, const std::string &adress, const float &salary, const std::string &PESEL, const Sex &sex, const Position &position) noexcept
{
    database_.push_back(std::make_shared<Employee>(Employee{name, surname, adress, salary, PESEL, sex, position}));
}

void Database::show() const noexcept
{
    system("clear");
    std::for_each(begin(database_), end(database_), [this](const auto ptr)
                  { printByPtr(ptr); });
}

void Database::printByPtr(const std::shared_ptr<Person> ptr) const noexcept
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

void Database::showBySurname(const std::string &surname) const noexcept
{
    system("clear");
    auto tempVec = findBySurname(surname);
    if (tempVec.size() == 0)
    {
        std::cout << "No records with given surname found" << std::endl;
    }
    else
    {
        std::for_each(begin(tempVec), end(tempVec), [this](const auto ptr)
                      { printByPtr(ptr); });
    }
}

void Database::showByPESEL(const std::string &PESEL) const noexcept
{
    system("clear");
    auto ptr = findByPESEL(PESEL);
    if (ptr == nullptr)
    {
        std::cout << "No records with given PESEL found" << std::endl;
    }
    else
    {
        printByPtr(ptr);
    }
}

std::vector<std::shared_ptr<Person>> Database::findBySurname(const std::string &surname) const noexcept
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

std::shared_ptr<Person> Database::findByPESEL(const std::string &PESEL) const noexcept
{
    auto tempIter = std::find_if(begin(database_), end(database_), [&PESEL](const auto el)
                                 { return el->getPESEL() == PESEL; });
    if (tempIter != end(database_))
    {
        return *(tempIter);
    }
    else
    {
        return nullptr;
    }
}

void Database::sortBySurname() noexcept
{
    std::sort(begin(database_), end(database_), [](auto lhs, auto rhs)
              { return lhs->getSurname() < rhs->getSurname(); });
}

void Database::sortByPESEL() noexcept
{
    std::sort(begin(database_), end(database_), [](auto lhs, auto rhs)
              { return lhs->getPESEL() < rhs->getPESEL(); });
}

void Database::sortBySalary() noexcept
{
    std::sort(begin(database_), end(database_), [](auto lhs, auto rhs)
              { return lhs->getSalary() < rhs->getSalary(); });
}

bool Database::removeByIndex(const int &index) noexcept
{
    if (database_.size() == 0)
    {
        std::cout << "No records in database" << std::endl;
        return false;
    }
    database_.erase(std::find_if(begin(database_), end(database_), [&index](const auto el)
                                 { return el->getIndex() == index; }));
    return true;
}

bool Database::modifySalary(const std::string &PESEL, const float &newSalary) noexcept
{

    std::shared_ptr<Person> tempPtr = findByPESEL(PESEL);
    if (tempPtr != nullptr && tempPtr->getPosition() == Position::Employee)
    {
        tempPtr->setSalary(newSalary);
        return true;
    }
    else
    {
        return false;
    }
}

bool Database::validatePESEL(const std::string &PESEL) const noexcept
{
    auto tempValidator = std::make_unique<PESELValidator>();
    return tempValidator->validatePESEL(PESEL);
}

void Database::loadFromFile(const std::string &fileName) noexcept
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

void Database::saveToFile(const std::string &fileName) noexcept
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

void Database::generateData(const int &n) noexcept
{
    auto tempGenerator = std::make_unique<RecordGenerator>();
    for (int i = 0; i < n; i++)
    {
        database_.push_back(std::move(tempGenerator->generateRandomRecord()));
    }
}

std::shared_ptr<Person> Database::getPtrToRecord(const int &pos) const noexcept
{
    return database_.at(pos);
}
