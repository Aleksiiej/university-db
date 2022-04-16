#include "RecordGenerator.hpp"

std::unique_ptr<Person> RecordGenerator::generateRandomRecord() const
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> distrib(0, 1);
    int maleOrFemale = distrib(rng);      // 0 - male, 1 - female
    int studentOrEmployee = distrib(rng); // 0 - student, 1 - employee

    Sex tempSex;
    std::string tempName;
    std::string tempSurname;

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

    std::unique_ptr<Person> tempPtr;
    switch (studentOrEmployee)
    {
    case 0:
        tempPtr = std::make_unique<Student>(Student{tempName, tempSurname, generateRandomAdress(), generateRandomIndex(), generateRandomPESEL(), tempSex, Position::Student});
        break;

    case 1:
        tempPtr = std::make_unique<Employee>(Employee{tempName, tempSurname, generateRandomAdress(), generateRandomSalary(), generateRandomPESEL(), tempSex, Position::Employee});
        break;
    }
    return tempPtr;
}

std::string RecordGenerator::generateRandomMaleName() const
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

std::string RecordGenerator::generateRandomFemaleName() const
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

std::string RecordGenerator::generateRandomMaleSurname() const
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

std::string RecordGenerator::generateRandomFemaleSurname() const
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

std::string RecordGenerator::generateRandomAdress() const
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

int RecordGenerator::generateRandomIndex() const
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

float RecordGenerator::generateRandomSalary() const
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

std::string RecordGenerator::generateRandomPESEL() const
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
