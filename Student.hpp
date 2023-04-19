#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <cstdint>
#include <string>


class Student
{
public:
    Student();
    ~Student() = default;

    void init();

    void setName(const std::string name);
    void setAge(uint8_t age);
    std::string getName(void);
private:
    std::string m_name;
    uint8_t m_age;
};

#endif // STUDENT_HPP