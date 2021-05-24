
#include "Timer.h"


namespace pitomba {

    void Timer::tick() {
        if (paused_) {
            return;
        }
        TimeUnit currentTime = now();
        deltaTimeFromLastFrame_ = currentTime - lastFrameTime_;
        lastFrameTime_ = currentTime;
        elapsedTime_ += deltaTimeFromLastFrame_;
    }

    void Timer::start() {
        if (!paused_) {
            return;
        }
        reset();
        paused_ = false;
    }

    void Timer::pause() {
        paused_ = true;
    }

    void Timer::resume() {
        paused_ = false;
    }

    void Timer::reset() {
        deltaTimeFromLastFrame_ = 0;
        lastFrameTime_ = now();
        elapsedTime_ = 0;
    }

    float Timer::fps() const {
        return 1000.0F / (float)deltaTimeFromLastFrame_;
    }

    TimeUnit Timer::elapsedTime() const {
        return elapsedTime_;
    }

    TimeUnit Timer::delta() const {
        return deltaTimeFromLastFrame_;
    }

}
