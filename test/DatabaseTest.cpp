#include <gtest/gtest.h>
#include "../Database.hpp"
#include "../Person.hpp"
#include "../Student.hpp"

class DatabaseFixture : public ::testing::Test
{
protected:
    void SetUp()
    {
        database.addStudent("Jan", "Nowak", "Gniezno, Jemiolowa 16", 217025, "93121312345", Sex::male);
        database.addStudent("Aleksandra", "Nowakowska", "Bydgoszcz, Zwyczajna 5", 126574, "93040523495", Sex::female);
        database.addStudent("Piotr", "Kowalski", "Warszawa, Przykladowa 20", 223412, "89275430298", Sex::male);
    }

    Database database;
    std::string testName{"Aleksandra"};
    std::string testSurname{"Nowakowska"};
    std::string testAdress{"Bydgoszcz, Zwyczajna 5"};
    int testIndex{126574};
    std::string testPESEL{"93040523495"};
    Sex testSex{Sex::female};
};

TEST_F(DatabaseFixture, addStudentTest)
{
    EXPECT_EQ(testName, database.getStudentRecord(1).getName());
    EXPECT_EQ(testSurname, database.getStudentRecord(1).getSurname());
    EXPECT_EQ(testAdress, database.getStudentRecord(1).getAdress());
    EXPECT_EQ(testIndex, database.getStudentRecord(1).getIndex());
    EXPECT_EQ(testPESEL, database.getStudentRecord(1).getPESEL());
    EXPECT_EQ(testSex, database.getStudentRecord(1).getSex());
}

TEST_F(DatabaseFixture, findBySurnameTest)
{
    std::vector<Student *> tempVec = database.findBySurname("Nowakowska");

    EXPECT_EQ(testName, tempVec.at(0)->getName());
    EXPECT_EQ(testSurname, tempVec.at(0)->getSurname());
    EXPECT_EQ(testAdress, tempVec.at(0)->getAdress());
    EXPECT_EQ(testIndex, tempVec.at(0)->getIndex());
    EXPECT_EQ(testPESEL, tempVec.at(0)->getPESEL());
    EXPECT_EQ(testSex, tempVec.at(0)->getSex());
}

TEST_F(DatabaseFixture, findByPESELTest)
{
    Student *tempPtr = database.findByPESEL("93040523495");

    EXPECT_EQ(testName, tempPtr->getName());
    EXPECT_EQ(testSurname, tempPtr->getSurname());
    EXPECT_EQ(testAdress, tempPtr->getAdress());
    EXPECT_EQ(testIndex, tempPtr->getIndex());
    EXPECT_EQ(testPESEL, tempPtr->getPESEL());
    EXPECT_EQ(testSex, tempPtr->getSex());
}

TEST_F(DatabaseFixture, sortBySurnameTest)
{
    database.sortBySurname();

    EXPECT_EQ(testName, database.getStudentRecord(2).getName());
    EXPECT_EQ(testSurname, database.getStudentRecord(2).getSurname());
    EXPECT_EQ(testAdress, database.getStudentRecord(2).getAdress());
    EXPECT_EQ(testIndex, database.getStudentRecord(2).getIndex());
    EXPECT_EQ(testPESEL, database.getStudentRecord(2).getPESEL());
    EXPECT_EQ(testSex, database.getStudentRecord(2).getSex());
}

TEST_F(DatabaseFixture, sortByPESELTest)
{
    database.sortByPESEL();

    EXPECT_EQ(testName, database.getStudentRecord(1).getName());
    EXPECT_EQ(testSurname, database.getStudentRecord(1).getSurname());
    EXPECT_EQ(testAdress, database.getStudentRecord(1).getAdress());
    EXPECT_EQ(testIndex, database.getStudentRecord(1).getIndex());
    EXPECT_EQ(testPESEL, database.getStudentRecord(1).getPESEL());
    EXPECT_EQ(testSex, database.getStudentRecord(1).getSex());
}

TEST_F(DatabaseFixture, removeTest)
{
    database.remove(217025);

    EXPECT_EQ(testName, database.getStudentRecord(0).getName());
    EXPECT_EQ(testSurname, database.getStudentRecord(0).getSurname());
    EXPECT_EQ(testAdress, database.getStudentRecord(0).getAdress());
    EXPECT_EQ(testIndex, database.getStudentRecord(0).getIndex());
    EXPECT_EQ(testPESEL, database.getStudentRecord(0).getPESEL());
    EXPECT_EQ(testSex, database.getStudentRecord(0).getSex());
}

TEST_F(DatabaseFixture, validatePESELTest)
{
    EXPECT_FALSE(database.validatePESEL(database.getStudentRecord(0).getPESEL()));
    EXPECT_TRUE(database.validatePESEL("95082910213"));
}
