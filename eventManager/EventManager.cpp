#include "EventManager.hpp"
#include <algorithm>
#include <sstream>
#include <iostream>
namespace Conn {
    
    EventManager::EventManager()
    {
    }
    
    EventManager& EventManager::getInstance()
    {
        static EventManager m_instance;
        return m_instance;
    }
    
    void EventManager::pushEvent(std::shared_ptr<Event> event)
    {
        std::cout << "event:" << to_String(event->getType()) << " has been pushed" << std::endl;
        
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.push(event);
        lock.unlock();
        m_cond.notify_one();
    }
    
    void EventManager::subscribeToEvent(EventType eventType, std::shared_ptr<EventSubscriber> eventSubscriber)
    {
        std::cout << "subscribe to event:" << to_String(eventType) << std::endl;
        if (m_eventsSubscribers.find(eventType) == m_eventsSubscribers.end())
        {
            std::vector<std::shared_ptr<EventSubscriber>> subscribers;
            subscribers.push_back(eventSubscriber);
            m_eventsSubscribers.emplace(eventType, subscribers);
        }
        else
        {
            m_eventsSubscribers[eventType].push_back(eventSubscriber);
        }
    }
    
    void EventManager::unsubscribeToEvent(EventType eventType, std::shared_ptr<EventSubscriber> eventSubscriber)
    {
        std::cout << "Unsubscribe to " << to_String(eventType) << std::endl;
    
        std::lock_guard<std::mutex> lock(m_mutex);
    
        if (m_eventsSubscribers.find(eventType) != m_eventsSubscribers.end())
        {
            if (m_eventsSubscribers[eventType].size() > 1)
            {
                m_eventsSubscribers[eventType].erase(std::find(
                    m_eventsSubscribers[eventType].begin(), m_eventsSubscribers[eventType].end(), eventSubscriber));
            }
            else
            {
                m_eventsSubscribers.erase(eventType);
            }
        }
    }
    void EventManager::unsubscribeToListOfEvents(const std::vector<EventType>& eventTypes,
                                                 std::shared_ptr<EventSubscriber> eventSubscriber)
    {
        for (const auto& eventType : eventTypes)
            unsubscribeToEvent(eventType, eventSubscriber);
    }
    
    void EventManager::subscribeToListOfEvents(const std::vector<EventType>& eventTypes,
                                               std::shared_ptr<EventSubscriber> eventSubscriber)
    {
        for (const auto& eventType : eventTypes)
            subscribeToEvent(eventType, eventSubscriber);
    }
    
    void EventManager::run()
    {
        while (true)
        {
            std::shared_ptr<Event> currentEvent;
            {
                std::unique_lock<std::mutex> mlock(m_mutex);
                m_cond.wait(mlock, [this]() { return !m_queue.empty(); });
                currentEvent = m_queue.front();
                m_queue.pop();
            }
    
            try
            {
                if (m_eventsSubscribers.find(currentEvent->getType()) != m_eventsSubscribers.end())
                    for (const auto& subscriber : m_eventsSubscribers[currentEvent->getType()])
                        subscriber->onNewEvent(currentEvent);
            }
            catch (const std::exception& ex)
            {
                std::cout << "Exception" << ex.what()
                                          << "caught while executing event:" << to_String(currentEvent->getType());
            }
        }
    }
}
