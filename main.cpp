#include <iostream>
#include "exampleClass.hpp"
#include "Student.hpp"

int main()
{
    gradStudent Ahmed;
    Ahmed.setName("Ahmed");
    Ahmed.setProfession("Engineer");
    Ahmed.setAge(15);
    std::cout << "Name: " << Ahmed.getName() << std::endl;
    std::cout << "Profession: " << Ahmed.getProfession() << std::endl;


    Student Mahmoud;
    Mahmoud.setName("Mahmoud");
    std::cout << "Name: " << Mahmoud.getName() << std::endl;

    return 0;
}