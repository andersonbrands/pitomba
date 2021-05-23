
#ifndef SERVICE_LOCATOR_H_
#define SERVICE_LOCATOR_H_

#include "../EventManager/iEventManager.h"
#include <memory>

namespace pitomba {

    class ServiceLocator {
    public:

        static std::shared_ptr<iEventManager> getEventManager() {
            return eventManager_;
        }

        static void provide(std::shared_ptr<iEventManager> eventManager) {
            eventManager_ = eventManager;
        }

    private:
        static std::shared_ptr<iEventManager> eventManager_;

    };
}

#endif // SERVICE_LOCATOR_H_
