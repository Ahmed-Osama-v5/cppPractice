#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "calc.hpp"

class mathTest : public testing::Test
{
public:
    mathClass obj;
private:
    void SetUp() override
    {
    }

    void TearDown() override
    {

    }
};

TEST_F(mathTest, sum)
{
    EXPECT_EQ(6, obj.sum(2, 3));
}

TEST(add, addSum)
{
    EXPECT_EQ(3, add(1, 2));
}