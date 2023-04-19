#ifndef EXAMPLE_CLASS_HPP
#define EXAMPLE_CLASS_HPP

#include "Student.hpp"
#include <cstdint>
#include <string>


#ifndef TEST_FRIEND_CLASS
#define TEST_FRIEND_CLASS
#endif //! TEST_FRIEND_CLASS
class gradStudent
{
    TEST_FRIEND_CLASS
public:
    gradStudent();
    ~gradStudent() = default;

    void setName(const std::string name);
    void setAge(uint8_t age);
    std::string getName(void);
    void setProfession(const std::string profession);
    std::string getProfession(void);
private:
    Student m_student{};
    std::string m_profession;
};


#endif // EXAMPLE_CLASS_HPP