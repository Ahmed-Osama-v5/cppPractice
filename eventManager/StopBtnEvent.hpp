#ifndef STOP_BTN_EVENT_H
#define STOP_BTN_EVENT_H

#include "Event.hpp"

namespace Conn {

    enum class StopBtnState {
        RELEASED,
        PRESSED
    };    
    class StopBtnEvent : public Event
    {

    public:
        StopBtnEvent(StopBtnState state)
            : Event(EventType::STOP_BTN_EVENT), m_state{ state }
        {
        }
        
        StopBtnState getStopBtnState() const
        {
            return m_state;
        }
    private:
        StopBtnState m_state{StopBtnState::RELEASED};
    };
}


#endif // STOP_BTN_EVENT_H
