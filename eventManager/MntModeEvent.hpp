#ifndef MNT_MODE_EVENT_H
#define MNT_MODE_EVENT_H

#include "Event.hpp"

namespace Conn {

    enum class MntModeState {
        INACTIVE,
        ACTIVE
    };    
    class MntModeEvent : public Event
    {

    public:
        MntModeEvent(MntModeState state)
            : Event(EventType::MNT_MODE_EVENT), m_state{ state }
        {
        }
        
        StopBtnState getMntModeState() const
        {
            return m_state;
        }
    private:
        StopBtnState m_state{MntModeState::INACTIVE};
    };
}


#endif // MNT_MODE_EVENT_H
