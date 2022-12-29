#include <iostream>
#include "Student.hpp"

Student::Student()
{

}

void Student::init()
{
    std::cout << "Student Init." << std::endl;
}

void Student::setName(std::string name)
{
    m_name = name;
}

std::string Student::getName()
{
    return m_name;
}