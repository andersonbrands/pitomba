
#include "Event.h"
#include <cassert>

namespace pitomba {
    Event::Event(EventId eventId)
        : id_(eventId) {}

    Event::~Event() {
        listeners_.clear();
    }

    void Event::send(void* pData) {
        for (EventHandlerListIterator iter = listeners_.begin(); iter != listeners_.end(); ++iter) {
            EventHandler* pEventHandler = *iter;
            assert(pEventHandler);
            if (pEventHandler) {
                pEventHandler->handleEvent(id_, pData);
            }
        }
    }

    void Event::attach(EventHandler& eventHandler) {
        listeners_.push_back(&eventHandler);
    }

    void Event::detach(const EventHandler& eventHandler) {
        for (EventHandlerListIterator iter = listeners_.begin(); iter != listeners_.end(); ++iter) {
            if (&eventHandler == *iter) {
                listeners_.erase(iter);
                break;
            }
        }
    }
}
