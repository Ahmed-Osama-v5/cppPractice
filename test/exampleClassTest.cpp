
#include "gmock/gmock.h"
#define TEST_FRIEND_CLASS friend class exampleClassTest;
#include "examleClass.hpp"
#include "gtest/gtest.h"
#include <sys/types.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include "exampleClass.hpp"
#include "Student.hpp"


class exampleClassTest : public ::testing::Test
{
protected:
    gradStudent Ahmed;
    Student &studentClient = Ahmed.m_student;

    void SetUp() override
    {
        Ahmed.setName("Ahmed");
        Ahmed.setAge(15);
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