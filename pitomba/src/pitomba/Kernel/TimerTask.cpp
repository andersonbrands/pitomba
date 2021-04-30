
#include "TimerTask.h"
#include "../Utils/Logger.h"
#include "RendererTask.h"
#include "../EventManager/EventManager.h"


namespace pitomba {

    TimerTask::TimerTask(const unsigned int priority) : Task(priority) {}

    void TimerTask::onStart() {
        timer_.start();
    }

    void TimerTask::onPause() {
        timer_.pause();
    }

    void TimerTask::onUpdate() {
        timer_.tick();

        auto gameTime = toSeconds(timer_.getElapsedTime());
        Logger::getInstancePtr()->debug(
            boost::format("GameTime (s): %1%\tFPS: %2%") % gameTime % timer_.getFPS()
        );
        sleep(1);

        // TODO remove
        if (timer_.getElapsedTime() >= 300) {
            EventManager::getInstancePtr()->sendEvent(ev::id::APPLICATION_QUIT);
        }
    }

    void TimerTask::onResume() {
        timer_.resume();
    }

    void TimerTask::onStop() {
        timer_.pause();
    }

}
