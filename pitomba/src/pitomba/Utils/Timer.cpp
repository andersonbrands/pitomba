
#include "Timer.h"


namespace pitomba {

    Timer::Timer() : deltaTimeFromLastFrame_(0), lastFrameTime_(now()), elapsedTime_(0), paused_(true) {

    }

    Timer::~Timer() {}

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
}
