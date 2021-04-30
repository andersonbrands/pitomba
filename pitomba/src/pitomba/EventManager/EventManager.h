
#ifndef EVENT_MANAGER_H_
#define EVENT_MANAGER_H_

#include "../Utils/Singleton.h"
#include <unordered_map>
#include "EventHandler.h"
#include "EventId.h"
#include "Event.h"

#include <cassert>


namespace pitomba {

    class EventManager : public Singleton<EventManager> {

    private:
        using EventMap = std::unordered_map<EventId, Event*>;
        using EventMapIterator = EventMap::iterator;

        EventMap eventMap_;
    public:
        EventManager() = default;
        ~EventManager();

        void registerEvent(EventId eventId);
        void unregisterEvent(EventId eventId);

        void attachEvent(EventId eventId, EventHandler& eventHandler);
        void detachEvent(EventId eventId, const EventHandler& eventHandler);

        void sendEvent(EventId eventId, void* pData = nullptr);
    };
}

#endif // EVENT_MANAGER_H_
