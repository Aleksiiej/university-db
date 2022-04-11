#include "Database.hpp"

void Database::addStudent(const std::string name, const std::string surname, const std::string adress, const int index, const std::string PESEL, const Sex sex)
{
    database_.push_back(Student(name, surname, adress, index, PESEL, sex));
    std::cout << std::endl;
}

void Database::addEmployee(const std::string name, const std::string surname, const std::string adress, const float salary, const std::string PESEL, const Sex sex)
{
    database_.push_back(Employee(name, surname, adress, salary, PESEL, sex));
    std::cout << std::endl;
}

void Database::show()
{
    system("clear");
    std::for_each(begin(database_), end(database_),
                  [this](auto &record)
                  { std::cout<<"==================================="<<std::endl;
      std::cout<<"Name: " << record.getName() << std::endl;
      std::cout<<"Surname: " << record.getSurname() << std::endl;
      std::cout<<"Adress: " << record.getAdress() << std::endl;
      if(record.classId == 1)
      {
          std::cout<<"Index: " << record.getIndex()<<std::endl;
      }
      else if (record.classId == 2)
      {
          std::cout<<"Salary: " << record.getSalary()<<std::endl;
      }
      std::cout<<"PESEL: " << record.getPESEL() << std::endl;
      std::cout<<"Sex: " << record.sexPrint[record.sex_] << std::endl;
      std::cout<<"===================================" << std::endl; });
}

void Database::printByPtr(Person *ptr) const
{
    std::cout << "===================================" << std::endl;
    std::cout << "Name: " << ptr->getName() << std::endl;
    std::cout << "Surname: " << ptr->getSurname() << std::endl;
    std::cout << "Adress: " << ptr->getAdress() << std::endl;
    if (ptr->classId == 2)
    {
        std::cout << "Index: " << ptr->getIndex() << std::endl;
    }
    else if (ptr->classId == 2)
    {
        std::cout << "Salary: " << ptr->getSalary() << std::endl;
    }
    std::cout << "PESEL: " << ptr->PESEL_ << std::endl;
    std::cout << "Sex: " << ptr->sexPrint[ptr->sex_] << std::endl;
    std::cout << "===================================" << std::endl;
}

void Database::showBySurname(const std::string surname)
{
    system("clear");
    auto tempVec = findBySurname(surname);

    std::for_each(begin(tempVec), end(tempVec), [this](const auto &ptr)
                  { printByPtr(ptr); });
}

void Database::showByPESEL(const std::string PESEL)
{
    system("clear");
    auto ptr = findByPESEL(PESEL);
    printByPtr(ptr);
}

std::vector<Person *> Database::findBySurname(std::string surname)
{
    std::vector<Person *> tempVec;
    for (auto &el : database_)
    {
        if (el.surname_ == surname)
        {
            Person *temp_ptr = &el;
            tempVec.push_back(temp_ptr);
        }
    }
    return tempVec;
}

Person *Database::findByPESEL(std::string PESEL)
{
    // Person* tempPtr;
    // for(auto el : database_)
    // {
    //     if(el.PESEL_ == PESEL)
    //     {
    //         tempPtr = &el;
    //         return tempPtr;
    //     }
    // }
    auto Iter = std::find_if(begin(database_), end(database_), [&PESEL](auto el)
                             { return el.getPESEL() == PESEL; });
    Person *ptr = &(*Iter);
    return ptr;
}

void Database::sortBySurname()
{
    std::sort(begin(database_), end(database_), [](auto a, auto b)
              { return a.surname_ < b.surname_; });
}

void Database::sortByPESEL()
{
    std::sort(begin(database_), end(database_), [](auto a, auto b)
              { return a.PESEL_ < b.PESEL_; });
}

void Database::remove(int index)
{
    database_.erase(std::find_if(begin(database_), end(database_), [&index](auto &el)
                                 { return el.getIndex() == index; }));
}

bool Database::validatePESEL(std::string PESEL) const
{
    if (PESEL.size() != 11)
    {
        std::cout << "PESEL is invalid" << std::endl;
        return false;
    }

    std::string Month = PESEL.substr(2, 2);
    std::string Day = PESEL.substr(4, 2);

    if (std::stoi(Month) < 1 && std::stoi(Month) > 12)
    {
        std::cout << "PESEL is invalid" << std::endl;
        return false;
    }
    if (std::stoi(Month) == 2 && (std::stoi(Day) < 1 || std::stoi(Day) > 29))
    {
        std::cout << "PESEL is invalid" << std::endl;
        return false;
    }
    if ((std::stoi(Month) == 4 || std::stoi(Month) == 6 || std::stoi(Month) == 9 || std::stoi(Month) == 11) && (std::stoi(Day) < 1 || std::stoi(Day) > 30))
    {
        std::cout << "PESEL is invalid" << std::endl;
        return false;
    }
    if ((std::stoi(Month) == 1 || std::stoi(Month) == 3 || std::stoi(Month) == 5 || std::stoi(Month) == 7 || std::stoi(Month) == 8 || std::stoi(Month) == 10 || std::stoi(Month) == 12) && (std::stoi(Day) < 1 && std::stoi(Day) > 31))
    {
        std::cout << "PESEL is invalid" << std::endl;
        return false;
    }

    std::vector<int> weights{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    std::transform(begin(weights), end(weights), begin(PESEL), begin(weights),
                   [](auto weight, auto PESELNumber)
                   { return weight * (PESELNumber - '0'); });
    std::string tempStr = std::to_string(std::accumulate(begin(weights), end(weights), 0));
    int controlNumber = 10 - (tempStr.back() - '0');

    if (controlNumber == (PESEL.back() - '0'))
    {
        std::cout << "PESEL is valid" << std::endl;
        return true;
    }
    else
    {
        std::cout << "PESEL is invalid" << std::endl;
        return false;
    }
}

void Database::loadFromFile()
{
    database_.clear();

    std::fstream file(fileName_, std::ios::in);

    if (!file)
    {
        std::cout << "File was not opened properly \n Program will be closed" << std::endl;
        exit(0);
    }

    std::string tempName;
    std::string tempSurname;
    std::string tempAdress;
    int tempIndex;
    std::string stringTempIndex;
    std::string tempPESEL;
    std::string tempSexString;
    Sex tempSex;

    int counter = 1;

    while (!file.eof())
    {
        if (counter % 6 == 1)
        {
            std::getline(file, tempName);
            counter++;
        }
        if (counter % 6 == 2)
        {
            std::getline(file, tempSurname);
            counter++;
        }
        if (counter % 6 == 3)
        {
            std::getline(file, tempAdress);
            counter++;
        }
        if (counter % 6 == 4)
        {
            std::getline(file, stringTempIndex);
            tempIndex = std::stoi(stringTempIndex);
            counter++;
        }
        if (counter % 6 == 5)
        {
            std::getline(file, tempPESEL);
            counter++;
        }
        if (counter % 6 == 0)
        {
            std::getline(file, tempSexString);
            tempSex = static_cast<Sex>(stoi(tempSexString));
            counter++;
        }

        database_.push_back(Student{tempName, tempSurname, tempAdress, tempIndex, tempPESEL, tempSex});
    }
}

void Database::saveToFile()
{
    std::fstream file(fileName_, std::ios::out);

    if (!file)
    {
        std::cout << "File was not opened properly \n Program will be closed" << std::endl;
        exit(0);
    }

    for (auto It = begin(database_); It != end(database_); It++)
    {
        std::cout << "Hello" << std::endl;
        file << It->name_ << std::endl;
        file << It->surname_ << std::endl;
        file << It->adress_ << std::endl;
        if (It->classId == 1)
        {
            file << It->getIndex() << std::endl;
        }
        else if (It->classId == 2)
        {
            file << It->getSalary() << std::endl;
        }
        file << It->PESEL_ << std::endl;
        file << static_cast<int>(It->sex_);
        if (It != (end(database_) - 1))
        {
            file << std::endl;
        }
    }
}

Person *Database::getStudentRecord(int pos)
{
    return &(database_.at(pos));
}

Person *Database::getEmployeeRecord(int pos)
{
    return &(database_.at(pos));
}