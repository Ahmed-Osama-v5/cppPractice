#ifndef EXAMPLE_CLASS_HPP
#define EXAMPLE_CLASS_HPP

#include "Student.hpp"
#include <string>

class gradStudent
{
public:
    gradStudent();
    ~gradStudent() = default;

    void setName(std::string name);
    std::string getName(void);
    void setProfession(std::string profession);
    std::string getProfession(void);
private:
    Student m_student{};
    std::string m_profession;
};


#endif // EXAMPLE_CLASS_HPP