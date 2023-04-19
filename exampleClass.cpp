#include "exampleClass.hpp"
#include <cstdint>

gradStudent::gradStudent()
{

}

void gradStudent::setName(const std::string name)
{
    m_student.setName(name);
}

void gradStudent::setAge(uint8_t age)
{
    m_student.setAge(age);
}

std::string gradStudent::getName()
{
    return m_student.getName();
}

void gradStudent::setProfession(std::string profession)
{
    m_profession = profession;
}

std::string gradStudent::getProfession()
{
    return m_profession;
}