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
        database.addEmployee("Renata", "Zaradna", "Ustrzyki, Powstancow Malopolskich 133", 4600.50, "73031054872", Sex::female, Position::Employee);
        database.addEmployee("Andrzej", "Niezbedny", "Sopot, Powstancow Slaskich 10", 4340.00, "78032559472", Sex::male, Position::Employee);
    }

    Database database;
    std::shared_ptr<Student> testStudent = std::make_shared<Student>("Aleksandra", "Nowakowska", "Bydgoszcz, Zwyczajna 5", 126574, "93040523495", Sex::female, Position::Student);
    std::shared_ptr<Employee> testEmployee = std::make_shared<Employee>("Andrzej", "Niezbedny", "Sopot, Powstancow Slaskich 10", 4340.00, "78032559472", Sex::male, Position::Employee);

    bool studentCompare(std::shared_ptr<Person> lhs, std::shared_ptr<Person> rhs)
    {
        if (lhs->getName() == rhs->getName() && lhs->getSurname() == rhs->getSurname() && lhs->getAdress() == rhs->getAdress() && lhs->getPESEL() == rhs->getPESEL() && lhs->getSex() == rhs->getSex() && lhs->getPosition() == rhs->getPosition() && lhs->getIndex() == rhs->getIndex())
        {
            return true;
        }
        else
            return false;
    }

    bool employeeCompare(std::shared_ptr<Person> lhs, std::shared_ptr<Person> rhs)
    {
        if (lhs->getName() == rhs->getName() && lhs->getSurname() == rhs->getSurname() && lhs->getAdress() == rhs->getAdress() && lhs->getPESEL() == rhs->getPESEL() && lhs->getSex() == rhs->getSex() && lhs->getPosition() == rhs->getPosition() && lhs->getSalary() == rhs->getSalary())
        {
            return true;
        }
        else
            return false;
    }
};

TEST_F(DatabaseFixture, addStudentTest)
{
    EXPECT_TRUE(studentCompare(testStudent, database.getPtrToRecord(1)));
}

TEST_F(DatabaseFixture, addEmployeeTest)
{
    EXPECT_TRUE(employeeCompare(testEmployee, database.getPtrToRecord(4)));
}

TEST_F(DatabaseFixture, findBySurnameTest)
{
    auto tempVec = database.findBySurname("Nowakowska");
    EXPECT_TRUE(studentCompare(tempVec.at(0), database.getPtrToRecord(1)));
}

TEST_F(DatabaseFixture, findByPESELTest)
{
    std::shared_ptr<Person> tempPtr = database.findByPESEL("93040523495");
    EXPECT_TRUE(studentCompare(testStudent, tempPtr));
}

TEST_F(DatabaseFixture, sortBySurnameTest)
{
    database.sortBySurname();
    EXPECT_TRUE(studentCompare(testStudent, database.getPtrToRecord(3)));
}

TEST_F(DatabaseFixture, sortByPESELTest)
{
    database.sortByPESEL();
    EXPECT_TRUE(studentCompare(testStudent, database.getPtrToRecord(3)));
}

TEST_F(DatabaseFixture, sortBySalary)
{
    database.sortBySalary();
    EXPECT_TRUE(employeeCompare(testEmployee, database.getPtrToRecord(3)));
}

TEST_F(DatabaseFixture, removeByIndexTest)
{
    database.removeByIndex(217025);
    EXPECT_TRUE(studentCompare(testStudent, database.getPtrToRecord(0)));
}

TEST_F(DatabaseFixture, modifySalaryTest)
{
    database.modifySalary("78032559472", 1000);
    EXPECT_EQ(database.getPtrToRecord(4)->getSalary(), 1000);
}
