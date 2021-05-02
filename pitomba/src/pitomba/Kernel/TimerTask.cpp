
#include "TimerTask.h"


namespace pitomba {

    TimerTask::TimerTask(const unsigned int priority) : Task(priority) {}

    TimeUnit TimerTask::getDelta() const {
        return timer_.getDeltaTimeFromLastFrame();
    }

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
