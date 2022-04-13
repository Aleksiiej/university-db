#include <gtest/gtest.h>
#include "../Database.hpp"
#include "../Person.hpp"
#include "../Student.hpp"

class DatabaseFixture : public ::testing::Test
{
protected:
    void SetUp()
    {
        database.addStudent("Jan", "Nowak", "Gniezno, Jemiolowa 16", 217025, "93121312345", Sex::male, Position::Student);
        database.addStudent("Aleksandra", "Nowakowska", "Bydgoszcz, Zwyczajna 5", 126574, "93040523495", Sex::female, Position::Student);
        database.addStudent("Piotr", "Kowalski", "Warszawa, Przykladowa 20", 223412, "89275430298", Sex::male, Position::Student);
        database.addEmployee("Andrzej", "Niezbedny", "Sopot, Powstancow Slaskich 10", 4600.50, "78032559472", Sex::male, Position::Employee);
    }

    Database database;
    std::string testStudentName{"Aleksandra"};
    std::string testStudentSurname{"Nowakowska"};
    std::string testStudentAdress{"Bydgoszcz, Zwyczajna 5"};
    int testStudentIndex{126574};
    std::string testStudentPESEL{"93040523495"};
    Sex testStudentSex{Sex::female};
    Position testStudentPosition{Position::Student};

    std::string testEmployeeName{"Andrzej"};
    std::string testEmployeeSurname{"Niezbedny"};
    std::string testEmployeeAdress{"Sopot, Powstancow Slaskich 10"};
    float testEmployeeSalary{4600.50};
    std::string testEmployeePESEL{"78032559472"};
    Sex testEmployeeSex{Sex::male};
    Position testEmployeePosition{Position::Employee};
};

TEST_F(DatabaseFixture, addStudentTest)
{
    EXPECT_EQ(testStudentName, database.getPtrToRecord(1)->getName());
    EXPECT_EQ(testStudentSurname, database.getPtrToRecord(1)->getSurname());
    EXPECT_EQ(testStudentAdress, database.getPtrToRecord(1)->getAdress());
    EXPECT_EQ(testStudentIndex, database.getPtrToRecord(1)->getIndex());
    EXPECT_EQ(testStudentPESEL, database.getPtrToRecord(1)->getPESEL());
    EXPECT_EQ(testStudentSex, database.getPtrToRecord(1)->getSex());
    EXPECT_EQ(testStudentPosition, database.getPtrToRecord(1)->getPosition());
}

TEST_F(DatabaseFixture, addEmployeeTest)
{
    EXPECT_EQ(testEmployeeName, database.getPtrToRecord(3)->getName());
    EXPECT_EQ(testEmployeeSurname, database.getPtrToRecord(3)->getSurname());
    EXPECT_EQ(testEmployeeAdress, database.getPtrToRecord(3)->getAdress());
    EXPECT_EQ(testEmployeeSalary, database.getPtrToRecord(3)->getSalary());
    EXPECT_EQ(testEmployeePESEL, database.getPtrToRecord(3)->getPESEL());
    EXPECT_EQ(testEmployeeSex, database.getPtrToRecord(3)->getSex());
    EXPECT_EQ(testEmployeePosition, database.getPtrToRecord(3)->getPosition());
}

TEST_F(DatabaseFixture, findBySurnameTest)
{
    std::vector<std::shared_ptr<Person>> tempVec = database.findBySurname("Nowakowska");

    EXPECT_EQ(testStudentName, tempVec.at(0)->getName());
    EXPECT_EQ(testStudentSurname, tempVec.at(0)->getSurname());
    EXPECT_EQ(testStudentAdress, tempVec.at(0)->getAdress());
    EXPECT_EQ(testStudentIndex, tempVec.at(0)->getIndex());
    EXPECT_EQ(testStudentPESEL, tempVec.at(0)->getPESEL());
    EXPECT_EQ(testStudentSex, tempVec.at(0)->getSex());
    EXPECT_EQ(testStudentPosition, tempVec.at(0)->getPosition());
}

TEST_F(DatabaseFixture, findByPESELTest)
{
    std::shared_ptr<Person> tempPtr = database.findByPESEL("93040523495");

    EXPECT_EQ(testStudentName, tempPtr->getName());
    EXPECT_EQ(testStudentSurname, tempPtr->getSurname());
    EXPECT_EQ(testStudentAdress, tempPtr->getAdress());
    EXPECT_EQ(testStudentIndex, tempPtr->getIndex());
    EXPECT_EQ(testStudentPESEL, tempPtr->getPESEL());
    EXPECT_EQ(testStudentSex, tempPtr->getSex());
    EXPECT_EQ(testStudentPosition, tempPtr->getPosition());
}

TEST_F(DatabaseFixture, sortBySurnameTest)
{
    database.sortBySurname();

    EXPECT_EQ(testStudentName, database.getPtrToRecord(3)->getName());
    EXPECT_EQ(testStudentSurname, database.getPtrToRecord(3)->getSurname());
    EXPECT_EQ(testStudentAdress, database.getPtrToRecord(3)->getAdress());
    EXPECT_EQ(testStudentIndex, database.getPtrToRecord(3)->getIndex());
    EXPECT_EQ(testStudentPESEL, database.getPtrToRecord(3)->getPESEL());
    EXPECT_EQ(testStudentSex, database.getPtrToRecord(3)->getSex());
    EXPECT_EQ(testStudentPosition, database.getPtrToRecord(3)->getPosition());
}

TEST_F(DatabaseFixture, sortByPESELTest)
{
    database.sortByPESEL();

    EXPECT_EQ(testStudentName, database.getPtrToRecord(2)->getName());
    EXPECT_EQ(testStudentSurname, database.getPtrToRecord(2)->getSurname());
    EXPECT_EQ(testStudentAdress, database.getPtrToRecord(2)->getAdress());
    EXPECT_EQ(testStudentIndex, database.getPtrToRecord(2)->getIndex());
    EXPECT_EQ(testStudentPESEL, database.getPtrToRecord(2)->getPESEL());
    EXPECT_EQ(testStudentSex, database.getPtrToRecord(2)->getSex());
    EXPECT_EQ(testStudentPosition, database.getPtrToRecord(2)->getPosition());
}

TEST_F(DatabaseFixture, removeTest)
{
    database.remove(217025);

    EXPECT_EQ(testStudentName, database.getPtrToRecord(0)->getName());
    EXPECT_EQ(testStudentSurname, database.getPtrToRecord(0)->getSurname());
    EXPECT_EQ(testStudentAdress, database.getPtrToRecord(0)->getAdress());
    EXPECT_EQ(testStudentIndex, database.getPtrToRecord(0)->getIndex());
    EXPECT_EQ(testStudentPESEL, database.getPtrToRecord(0)->getPESEL());
    EXPECT_EQ(testStudentSex, database.getPtrToRecord(0)->getSex());
    EXPECT_EQ(testStudentPosition, database.getPtrToRecord(0)->getPosition());
}

TEST_F(DatabaseFixture, validatePESELTest)
{
    EXPECT_FALSE(database.validatePESEL(database.getPtrToRecord(0)->getPESEL()));
    EXPECT_TRUE(database.validatePESEL("95082910213"));
}


