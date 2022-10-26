#ifndef BATTA_HPP
#define BATTA_HPP

#include <iostream>
#include <string>

namespace strategy
{

    /* Forward declaration */
    class FlyBehavior;


    class Batta
    {
    public:
        Batta();
        ~Batta()
        {
            delete myFlyBehavior;
        }

        std::string swim();
        virtual std::string display() = 0;
        void perform();
        std::string getName();

    protected:
        FlyBehavior* myFlyBehavior;

    private:
        int m_id;
        std::string m_name;
        static int m_counter;
    };

    class FlyBehavior
    {
        public:
            virtual std::string fly() = 0;
    };

    class FlyWithWings : public FlyBehavior
    {
        public:
            //FlyWithWings();
            std::string fly() override;
    };

    class FlyWithMotor : public FlyBehavior
    {
        public:
            //FlyWithMotor();
            std::string fly() override;
    };

    class NoFly : public FlyBehavior
    {
        public:
            //NoFly();
            std::string fly() override;
    };

    class Mo7bata : public Batta
    {
        public:
            Mo7bata()
            {
                delete this->myFlyBehavior;
                this->myFlyBehavior = new FlyWithWings();
            }
            std::string display() override;

            void gotShot();
    };

    class Le3ba : public Batta
    {
        public:
            Le3ba()
            {
                delete this->myFlyBehavior;
                this->myFlyBehavior = new FlyWithMotor();
            }
            std::string display() override;
    };

    class Mescoofy : public Batta
    {
        public:
            Mescoofy()
            {
                delete this->myFlyBehavior;
                this->myFlyBehavior = new FlyWithWings();
            }
            std::string display() override;
    };
}



#endif // BATTA_HPP