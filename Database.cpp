#include "Database.hpp"

void Database::addStudent(const std::string name, const std::string surname, const std::string adress, const int index, const std::string PESEL, const std::string sex)
{
    database_.push_back(Student(name, surname, adress, index, PESEL, sex));
    std::cout << std::endl;
}

void Database::show() const
{
    system("clear");
    std::for_each(begin(database_), end(database_),
                  [](const auto &record)
                  { std::cout<<"==================================="<<std::endl;
      std::cout<<"Name: " << record.name_<<std::endl;
      std::cout<<"Surname: " << record.surname_<<std::endl;
      std::cout<<"Adress: " << record.adress_<<std::endl;
      std::cout<<"Index: " << record.index_<<std::endl;
      std::cout<<"PESEL: " << record.PESEL_<<std::endl;
      std::cout<<"Sex: " << record.sex_<<std::endl;
      std::cout<<"==================================="<<std::endl; });
}

void Database::printByPtr(Student *ptr) const
{
    std::cout << "===================================" << std::endl;
    std::cout << "Name: " << ptr->name_ << std::endl;
    std::cout << "Surname: " << ptr->surname_ << std::endl;
    std::cout << "Adress: " << ptr->adress_ << std::endl;
    std::cout << "Index: " << ptr->index_ << std::endl;
    std::cout << "PESEL: " << ptr->PESEL_ << std::endl;
    std::cout << "Sex: " << ptr->sex_ << std::endl;
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

std::vector<Student *> Database::findBySurname(std::string surname)
{
    std::vector<Student *> tempVec;
    for (auto &el : database_)
    {
        if (el.surname_ == surname)
        {
            Student *temp_ptr = &el;
            tempVec.push_back(temp_ptr);
        }
    }
    return tempVec;
}

Student *Database::findByPESEL(std::string PESEL)
{
    auto Iter = std::find_if(begin(database_), end(database_), [&PESEL](auto el)
                             { return el.PESEL_ == PESEL; });
    Student *ptr = &(*Iter);
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
    database_.erase(std::find_if(begin(database_), end(database_), [&index](auto el)
                                 { return el.index_ == index; }));
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
    std::string tempSex;

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
            std::getline(file, tempSex);
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
        file << It->index_ << std::endl;
        file << It->PESEL_ << std::endl;
        file << It->sex_;
        if (It != (end(database_) - 1))
        {
            file << std::endl;
        }
    }
}

Student Database::getStudentRecord(int pos)
{
    return database_.at(pos);
}