#ifndef EVENT_SUBSCRIBER_H
#define EVENT_SUBSCRIBER_H

#include <memory>
#include "Event.hpp"

namespace Conn {
    
    class EventSubscriber {
      public:
        virtual void onNewEvent(std::shared_ptr<Event> event) = 0;
    };
}

#endif // EVENT_SUBSCRIBER_H
