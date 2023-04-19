#ifndef STUDENTMOCK_HPP
#define STUDENTMOCK_HPP

#include "exampleClass.hpp"
#include <cstdint>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

class gradStudentMock : public gradStudent
{
public:
  MOCK_METHOD1(setName, void(const std::string));
  MOCK_METHOD1(setAge, void(uint8_t));
  MOCK_METHOD1(setProfession, void(const std::string));
  MOCK_METHOD0(getName, std::string(void));
  MOCK_METHOD0(getProfession, std::string(void));
};

#endif // STUDENTMOCK_HPP