
#ifndef EVENT_MANAGER_H_
#define EVENT_MANAGER_H_


#include "iEventManager.h"
#include "Event.h"
#include <unordered_map>


namespace pitomba {

    class EventManager : public iEventManager {

    private:
        using EventMap = std::unordered_map<EventId, Event*>;
        using EventMapIterator = EventMap::iterator;

        EventMap eventMap_;
    public:
        EventManager() = default;
        ~EventManager() final;

        void registerEvent(EventId eventId) override;
        void unregisterEvent(EventId eventId) override;

        void attachEvent(EventId eventId, EventHandler& eventHandler) override;
        void detachEvent(EventId eventId, const EventHandler& eventHandler) override;

        void sendEvent(EventId eventId, void* pData = nullptr) override;
    };
}

#endif // EVENT_MANAGER_H_
