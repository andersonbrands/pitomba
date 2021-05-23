
#ifndef SERVICE_LOCATOR_H_
#define SERVICE_LOCATOR_H_

#include "../EventManager/iEventManager.h"
#include "../Utils/iRng.h"
#include <memory>

namespace pitomba {

    class ServiceLocator {
    public:

        static std::shared_ptr<iEventManager> getEventManager() {
            return eventManager_;
        }

        static std::shared_ptr<iRng> getRng() {
            return rng_;
        }

        static void provide(std::shared_ptr<iEventManager> eventManager) {
            eventManager_ = eventManager;
        }

        static void provide(std::shared_ptr<iRng> rng) {
            rng_ = rng;
        }

    private:
        static std::shared_ptr<iEventManager> eventManager_;
        static std::shared_ptr<iRng> rng_;

    };
}

#endif // SERVICE_LOCATOR_H_
