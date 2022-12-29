#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
class Student
{
public:
    Student();
    ~Student() = default;

    void init();

    void setName(std::string name);
    std::string getName(void);
private:
    std::string m_name;
};

#endif // STUDENT_HPP