#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "exampleClass.hpp"
#include "Student.hpp"

class exampleClassTest : public testing::Test
{
protected:
    gradStudent Ahmed;
    //Student &student = Ahmed.m_student;
private:
    void SetUp() override
    {
        Ahmed.setName("Ahmed");
        Ahmed.setProfession("Engineer");
    }

    void TearDown() override
    {

    }
};

TEST_F(exampleClassTest, Name)
{
    EXPECT_EQ("Ahmed", Ahmed.getName());
}

TEST_F(exampleClassTest, profession)
{
    EXPECT_EQ("Engineer", Ahmed.getProfession());
}