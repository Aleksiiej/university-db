#include "RecordGenerator.hpp"

std::unique_ptr<Person> RecordGenerator::generateRandomRecord() const noexcept
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
        tempPtr = std::make_unique<Student>(Student{tempName, tempSurname, generateRandomAdress(), generateRandomIndex(), generateRandomPESEL(tempSex), tempSex, Position::Student});
        break;

    case 1:
        tempPtr = std::make_unique<Employee>(Employee{tempName, tempSurname, generateRandomAdress(), generateRandomSalary(), generateRandomPESEL(tempSex), tempSex, Position::Employee});
        break;
    }
    return tempPtr;
}

std::string RecordGenerator::generateRandomMaleName() const noexcept
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

std::string RecordGenerator::generateRandomFemaleName() const noexcept
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

std::string RecordGenerator::generateRandomMaleSurname() const noexcept
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

std::string RecordGenerator::generateRandomFemaleSurname() const noexcept
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

std::string RecordGenerator::generateRandomAdress() const noexcept
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

int RecordGenerator::generateRandomIndex() const noexcept
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> distrib(minIndex, maxIndex);
    return distrib(rng);
}

float RecordGenerator::generateRandomSalary() const noexcept
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> distrib(minSalary, maxSalary);
    return distrib(rng);
}

std::string RecordGenerator::generateRandomPESEL(const Sex &sex) const noexcept
{
    std::string tempPESEL;
    tempPESEL = generatePESELDate(tempPESEL);          // Date
    tempPESEL = generatePESELSex(tempPESEL, sex);      // Sex
    tempPESEL = generatePESELControlNumber(tempPESEL); // Control number
    return tempPESEL;
}

std::string RecordGenerator::generatePESELDate(std::string &tempPESEL) const noexcept
{
    std::random_device rd;
    std::mt19937 rng(rd());

    // Year

    std::uniform_int_distribution<> distrib(minYearIfBirth, maxYearOfBirth);
    int yearOfBirth = distrib(rng);
    std::string tempYear = std::to_string(yearOfBirth);
    tempPESEL = tempPESEL + tempYear.at(2) + tempYear.at(3);

    // Month

    distrib = std::uniform_int_distribution<>(1, 12);
    int monthOfBirth = distrib(rng);
    if (monthOfBirth < 10)
    {
        tempPESEL += "0";
    }
    tempPESEL += std::to_string(monthOfBirth);

    // Day

    if (monthOfBirth == 1 || monthOfBirth == 3 || monthOfBirth == 5 || monthOfBirth == 7 || monthOfBirth == 8 || monthOfBirth == 10 || monthOfBirth == 12)
    {
        distrib = std::uniform_int_distribution<>(1, 31);
        int dayOfBirth = distrib(rng);
        if (dayOfBirth < 10)
        {
            tempPESEL += "0";
        }
        tempPESEL += std::to_string(dayOfBirth);
    }
    else if (monthOfBirth == 2 || monthOfBirth == 4 || monthOfBirth == 6 || monthOfBirth == 9 || monthOfBirth == 11)
    {
        distrib = std::uniform_int_distribution<>(1, 30);
        int dayOfBirth = distrib(rng);
        if (dayOfBirth < 10)
        {
            tempPESEL += "0";
        }
        tempPESEL += std::to_string(dayOfBirth);
    }
    else if (monthOfBirth == 2)
    {
        if (yearOfBirth % 4 == 0 || (yearOfBirth % 100 == 0 && yearOfBirth % 400 == 0))
        {
            distrib = std::uniform_int_distribution<>(1, 29);
            int dayOfBirth = distrib(rng);
            if (dayOfBirth < 10)
            {
                tempPESEL += "0";
            }
            tempPESEL += std::to_string(dayOfBirth);
        }
        else
        {
            distrib = std::uniform_int_distribution<>(1, 28);
            int dayOfBirth = distrib(rng);
            if (dayOfBirth < 10)
            {
                tempPESEL += "0";
            }
            tempPESEL += std::to_string(dayOfBirth);
        }
    }
    return tempPESEL;
}

std::string RecordGenerator::generatePESELSex(std::string &tempPESEL, const Sex &sex) const noexcept
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> distrib(0, 9);
    for (int i = 0; i < 3; i++)
    {
        tempPESEL += std::to_string(distrib(rng));
    }

    distrib = std::uniform_int_distribution<>(0, 9);
    int number = distrib(rng);
    switch (sex)
    {
    case Sex::male:
        while (number % 2 == 0)
        {
            number = distrib(rng);
        }
        tempPESEL += std::to_string(number);
        break;

    case Sex::female:
        while (number % 2 != 0)
        {
            number = distrib(rng);
        }
        tempPESEL += std::to_string(number);
        break;
    }
    return tempPESEL;
}

std::string RecordGenerator::generatePESELControlNumber(std::string &tempPESEL) const noexcept
{
    std::vector<int> weights{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    std::transform(begin(weights), end(weights), begin(tempPESEL), begin(weights),
                   [](auto weight, auto PESELNumber)
                   { return weight * (PESELNumber - '0'); });
    std::string tempStr = std::to_string(std::accumulate(begin(weights), end(weights), 0));
    int controlNumber = 10 - (tempStr.back() - '0');
    if (controlNumber == 10)
    {
        controlNumber = 0;
    }
    tempPESEL += std::to_string(controlNumber);
    return tempPESEL;
}
