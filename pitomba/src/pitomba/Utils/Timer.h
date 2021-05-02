
#ifndef TIMER_H_
#define TIMER_H_

#include "Utils.h"


namespace pitomba {

    class Timer {

    private:
        TimeUnit deltaTimeFromLastFrame_ = 0;
        TimeUnit lastFrameTime_ = now();
        TimeUnit elapsedTime_ = 0;
        bool paused_ = true;

        void reset();

    public:
        Timer() = default;
        virtual ~Timer() = default;

        void tick();
        void start();
        void pause();
        void resume();

        float getFPS() const;
        TimeUnit getElapsedTime() const;
        TimeUnit getDeltaTimeFromLastFrame() const;
    };

    inline float Timer::getFPS() const {
        return 1000.0F / (float)deltaTimeFromLastFrame_;
    }

    inline TimeUnit Timer::getElapsedTime() const {
        return elapsedTime_;
    }

    inline TimeUnit Timer::getDeltaTimeFromLastFrame() const {
        return deltaTimeFromLastFrame_;
    }

}

#endif // TIMER_H_