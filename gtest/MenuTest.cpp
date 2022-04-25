#include <gtest/gtest.h>
#include "DatabaseMock.hpp"
#include "../Menu.hpp"

class MenuFixture : public ::testing::Test
{
public:
    testing::NiceMock<DatabaseMock> db;
    Menu menu{db};
};
