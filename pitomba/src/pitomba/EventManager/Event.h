
#ifndef EVENT_H_
#define EVENT_H_

#include <vector>
#include "EventId.h"
#include "EventHandler.h"

namespace pitomba {

    class Event {
    private:
        using EventHandlerList = std::vector<EventHandler*>;
        using EventHandlerListIterator = EventHandlerList::iterator;

        EventHandlerList listeners_;
        EventId id_;
    public:
        explicit Event(EventId eventId);
        ~Event();

        void send(void* pData);

        void attach(EventHandler& eventHandler);
        void detach(const EventHandler& eventHandler);

        EventId getID() const {
            return id_;
        }
    };
}

#endif // EVENT_H_