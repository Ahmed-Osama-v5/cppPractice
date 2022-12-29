#include "exampleClass.hpp"

gradStudent::gradStudent()
{

}

void gradStudent::setName(std::string name)
{
    m_student.setName(name);
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