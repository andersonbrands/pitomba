
#ifndef TIMER_H_
#define TIMER_H_

#include "Utils.h"


namespace pitomba {

    class Timer {

    private:
        int deltaTimeFromLastFrame_;
        TimeUnit lastFrameTime_;
        TimeUnit elapsedTime_;
        bool paused_;

        void reset();

    public:
        Timer();
        virtual ~Timer();

        void tick();
        void start();
        void pause();
        void resume();

        float getFPS() const;
        TimeUnit getElapsedTime() const;

    protected:

    };

    inline float Timer::getFPS() const {
        return 1000.0f / (float)deltaTimeFromLastFrame_;
    }

    inline TimeUnit Timer::getElapsedTime() const {
        return elapsedTime_;
    }

}

#endif // TIMER_H_