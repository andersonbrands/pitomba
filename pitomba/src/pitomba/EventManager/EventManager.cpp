
#include "EventManager.h"
#include <cassert>

namespace pitomba {

    EventManager::~EventManager() {
        for (EventMapIterator iter = eventMap_.begin(); iter != eventMap_.end(); ++iter) {
            Event* pEvent = iter->second;
            if (pEvent) {
                delete pEvent;
                iter->second = NULL;
            }
        }

        eventMap_.clear();
    }

    void EventManager::registerEvent(EventId eventId) {
        EventMapIterator result = eventMap_.find(eventId);
        assert(result == eventMap_.end());

        auto pNewEvent = new Event(eventId);

        std::pair<EventId, Event*> newEvent(eventId, pNewEvent);
        std::pair<EventMapIterator, bool> addedIter = eventMap_.insert(newEvent);
    }

    void EventManager::unregisterEvent(EventId eventId) {
        EventMapIterator result = eventMap_.find(eventId);
        assert(result != eventMap_.end());
        eventMap_.erase(result);
    }

    void EventManager::attachEvent(EventId eventId, EventHandler& eventHandler) {
        EventMapIterator result = eventMap_.find(eventId);
        assert(result != eventMap_.end());

        assert(result->second);
        result->second->attach(eventHandler);
    }

    void EventManager::detachEvent(EventId eventId, const EventHandler& eventHandler) {
        EventMapIterator result = eventMap_.find(eventId);
        assert(result != eventMap_.end());

        result->second->detach(eventHandler);
    }

    void EventManager::sendEvent(EventId eventId, void* pData) {
        EventMapIterator result = eventMap_.find(eventId);
        assert(result != eventMap_.end());
        result->second->send(pData);
    }

}