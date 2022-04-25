#include <gtest/gtest.h>
#include "../PESELValidator.hpp"

TEST(PESELValidatorTests, validatePESELTest)
{
    PESELValidator pv;
    EXPECT_FALSE(pv.validatePESEL("94063134978"));
    EXPECT_TRUE(pv.validatePESEL("58052089564"));
}