
#ifndef SERVICE_LOCATOR_H_
#define SERVICE_LOCATOR_H_

#include "../EventManager/iEventManager.h"
#include "../Utils/iRng.h"
#include "../Utils/iTimer.h"
#include "../Renderer/iRenderer.h"

namespace pitomba {

    class ServiceLocator {
    public:

        static iEventManager* getEventManager() {
            return eventManager_;
        }

        static iRng* getRng() {
            return rng_;
        }

        static iTimer* getTimer() {
            return timer_;
        }

        static iRenderer* getRenderer() {
            return renderer_;
        }

        static void provide(iEventManager* eventManager) {
            eventManager_ = eventManager;
        }

        static void provide(iRng* rng) {
            rng_ = rng;
        }

        static void provide(iTimer* timer) {
            timer_ = timer;
        }

        static void provide(iRenderer* renderer) {
            renderer_ = renderer;
        }


    private:
        static iEventManager* eventManager_;
        static iRng* rng_;
        static iTimer* timer_;
        static iRenderer* renderer_;

    };
}

#endif // SERVICE_LOCATOR_H_