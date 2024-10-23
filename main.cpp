#include <iostream>
#include <thread>
#include "EventSubscriber.hpp"
#include "EventManager.hpp"
#include "StopBtnEvent.hpp"
#include "MntModeEvent.hpp"

namespace Conn{
    
    class StopBtnEvent;
    class MntModeEvent;

    class Controller : public EventSubscriber, public std::enable_shared_from_this<Controller> {
        public:
            Controller() = default;
            ~Controller() = default;
            
            void init();
            void run();
        private:
            void onNewEvent(std::shared_ptr<Event> event) override;
    };
    
    void Controller::init() {
        EventManager::getInstance().subscribeToListOfEvents({   EventType::STOP_BTN_EVENT,
                                                                EventType::MNT_MODE_EVENT},
                                                                static_cast<std::shared_ptr<EventSubscriber>>(this));
    }
    
    void Controller::run() {
        std::thread eventMngrThread([]() { EventManager::getInstance().run(); });
        eventMngrThread.detach();
        
        EventManager::getInstance().pushEvent(std::make_shared<StopBtnEvent>(StopBtnState::RELEASED));
        EventManager::getInstance().pushEvent(std::make_shared<MntModeEvent>(MntModeState::ACTIVE));
    }
    
    void Controller::onNewEvent(std::shared_ptr<Event> event) {
        std::cout << "new event triggered" << std::endl;
        if(event != nullptr)
        {
            switch(event->getType())
            {
                case EventType::STOP_BTN_EVENT:
                    std::cout << "Received STOP_BTN event" << std::endl;
                    std::cout << "new state: " << event->get << std::endl;
                    break;
                case EventType::MNT_MODE_EVENT:
                    std::cout << "Received MNT_MODE event" << std::endl;
                    break;
                default:
                    std::cout << "Unknown event" << std::endl;
                    break;
            }
        }
        else
        {
            std::cout << "Received NULL event !!";
        }
    }
}

    
int main()
{
    using namespace Conn;
    Controller controller;
    std::cout<<"Init:" << std::endl;
    controller.init();
    std::cout<<"Run:" << std::endl;
    controller.run();
    
    while(1);

    return 0;
}
