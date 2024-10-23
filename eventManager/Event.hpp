#ifndef EVENT_H
#define EVENT_H

#include <string>

namespace Conn {
    
    enum class EventType {
      STOP_BTN_EVENT,
      MNT_MODE_EVENT
    };
    
    inline std::string to_String(EventType event) {
        
        switch(event) {
            case EventType::STOP_BTN_EVENT:
                return "STOP_BTN_EVENT";
            case EventType::MNT_MODE_EVENT:
                return "MNT_MODE_EVENT";
            default:
                return "UNKNOWN";
        }
    }
    
    class Event {
      public:
        Event(EventType type) : m_type(type) {}
        virtual ~Event() = default;
        
        EventType getType() const {
            return m_type;
        }
        
      private:
        EventType m_type;
    };
}

#endif // EVENT_H
