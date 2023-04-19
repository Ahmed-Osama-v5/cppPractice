#include <cstdint>
#include <iostream>
#include "Student.hpp"

Student::Student()
{

}

void Student::init()
{
    std::cout << "Student Init." << std::endl;
}

void Student::setName(const std::string name)
{
    m_name = name;
}

void Student::setAge(uint8_t age)
{
    m_age = age;
}

std::string Student::getName()
{
    return m_name;
}
