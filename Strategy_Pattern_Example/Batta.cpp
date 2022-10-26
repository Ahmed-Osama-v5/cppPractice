#include <iostream>
#include "Batta.hpp"

namespace strategy
{
    int Batta::m_counter = 0;
    Batta::Batta()
    {
        this->m_id = m_counter++;
        this->m_name = std::string("Batta#") + std::to_string(this->m_id);
        this->myFlyBehavior = new FlyWithWings();
    }

    std::string Batta::swim()
    {
        return "I am swimming !";
    }

    void Batta::perform()
    {
        std::cout << "***************" << std::endl;
        std::cout << "Hi I am " + this->m_name << std::endl;
        std::cout << this->display() << std::endl;
        std::cout << this->swim() << std::endl;
        std::cout << this->myFlyBehavior->fly() << std::endl << std::endl;
    }
    std::string Batta::getName()
    {
        return this->m_name;
    }

    std::string FlyWithWings::fly()
    {
        return "I fly with wings !";
    }

    std::string FlyWithMotor::fly()
    {
        return "I fly with motor !";
    }

    std::string NoFly::fly()
    {
        return "I can't fly !";
    }

    std::string Mo7bata::display()
    {
        return "I am Mo7bata !";
    }

    std::string Le3ba::display()
    {
        return "I am Le3ba !";
    }

    std::string Mescoofy::display()
    {
        return "I am Mescoofy !";
    }

    void Mo7bata::gotShot()
    {
        delete myFlyBehavior;
        this->myFlyBehavior = new NoFly();
        std::cout << "Hi I am " + this->getName() << ", I got shot :(" << std::endl;
    }
}