#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "Event.hpp"
#include "EventSubscriber.hpp"
#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <unordered_map>
#include <vector>

namespace Conn
{
    class EventManager
    {
    public:
        EventManager(const EventManager& eventManager) = delete;
        EventManager& operator=(const EventManager& eventManager) = delete;

        static EventManager& getInstance();
        void pushEvent(std::shared_ptr<Event> event);
        void subscribeToEvent(EventType eventType, std::shared_ptr<EventSubscriber> eventSubscriber);
        void subscribeToListOfEvents(const std::vector<EventType>& eventTypes,
                                     std::shared_ptr<EventSubscriber> eventSubscriber);
        void unsubscribeToEvent(EventType eventType, std::shared_ptr<EventSubscriber> eventSubscriber);
        void unsubscribeToListOfEvents(const std::vector<EventType>& eventTypes,
                                       std::shared_ptr<EventSubscriber> eventSubscriber);
        void run();

    private:
        EventManager();
        ~EventManager() = default;

        std::mutex m_mutex;
        std::condition_variable m_cond;

        std::queue<std::shared_ptr<Event>> m_queue;
        std::unordered_map<EventType, std::vector<std::shared_ptr<EventSubscriber>>> m_eventsSubscribers;
    };
} // namespace Conn

#endif // EVENT_MANAGER_H
