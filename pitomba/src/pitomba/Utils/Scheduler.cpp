
#include "Scheduler.h"
#include <cassert>


namespace pitomba {
    void Scheduler::tick(TimeUnit delta) {
        if (!func_) {
            return;
        }

        counter_ += delta;

        int ref = timesCounter_ == 0 ? (int)timeout_ : (int)interval_;

        if (counter_ >= ref) {
            counter_ = counter_ - ref;
            trigger();
        }

    }

    void Scheduler::setInterval(int interval, std::function<void()> func, int timeout, int times) {
        interval_ = interval;
        func_ = func;
        timeout_ = timeout;
        times_ = times;
        counter_ = 0;
        timesCounter_ = 0;
    }

    void Scheduler::setTimeout(int timeout, std::function<void()> func) {
        setInterval(0, func, timeout, 1);
    }

    void Scheduler::trigger() {
        assert(func_);

        func_();

        timesCounter_++;
        if (times_ && timesCounter_ == times_) {
            func_ = nullptr;
        }
    }
}
