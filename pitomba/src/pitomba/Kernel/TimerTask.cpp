
#include "TimerTask.h"
#include "../Utils/Timer.h"

namespace pitomba {

    TimerTask::TimerTask(const unsigned int priority) : Task(priority) {}

    iTimer* TimerTask::getTimer() const {
        return pTimer_;
    }

    void TimerTask::onStart() {
        pManagedTimer_->start();
    }

    void TimerTask::onPause() {
        pManagedTimer_->pause();
    }

    void TimerTask::onUpdate() {
        pManagedTimer_->tick();
    }

    void TimerTask::onResume() {
        pManagedTimer_->resume();
    }

    void TimerTask::onStop() {
        pManagedTimer_->pause();
    }

}
