#include <gtest/gtest.h>
#include <memory>
#include "../RecordGenerator.hpp"

TEST(RecordGeneratorTests, generateRandomRecordTest)
{
    RecordGenerator rg;
    std::unique_ptr<Person> record = std::move(rg.generateRandomRecord());
    EXPECT_LT(0, (record->getName()).size());
    EXPECT_LT(0, (record->getSurname()).size());
    EXPECT_LT(0, (record->getAdress()).size());
    if (record->getPosition() == Position::Student)
    {
        EXPECT_LE(20000, record->getIndex());
        EXPECT_GE(39999, record->getIndex());
    }
    else if (record->getPosition() == Position::Employee)
    {
        EXPECT_LE(2000, record->getSalary());
        EXPECT_GE(6000, record->getSalary());
    }
    EXPECT_EQ(11, (record->getPESEL()).size());
}