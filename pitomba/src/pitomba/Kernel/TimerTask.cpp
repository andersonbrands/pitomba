
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
    }

    void TimerTask::onResume() {
        timer_.resume();
    }

    void TimerTask::onStop() {
        timer_.pause();
    }

}
