
#ifndef EVENT_HANDLER_H_
#define EVENT_HANDLER_H_

#include "EventId.h"


namespace pitomba {

    class EventHandler {
    public:
        virtual ~EventHandler() = default;

        virtual void handleEvent(EventId eventId, void* pData) = 0;
    };
}

#endif // EVENT_HANDLER_H_
