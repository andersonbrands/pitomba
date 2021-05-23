
#ifndef I_EVENT_MANAGER_H_
#define I_EVENT_MANAGER_H_

#include "EventId.h"
#include "EventHandler.h"


namespace pitomba {

    class iEventManager {

    public:
        iEventManager() = default;
        virtual ~iEventManager() = default;

        virtual void registerEvent(EventId eventId) = 0;
        virtual void unregisterEvent(EventId eventId) = 0;

        virtual void attachEvent(EventId eventId, EventHandler& eventHandler) = 0;
        virtual void detachEvent(EventId eventId, const EventHandler& eventHandler) = 0;

        virtual void sendEvent(EventId eventId, void* pData = nullptr) = 0;
    };
}

#endif // I_EVENT_MANAGER_H_
