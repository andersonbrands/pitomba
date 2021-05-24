
#ifndef TIMER_H_
#define TIMER_H_

#include "iTimer.h"
#include "iManagedTimer.h"


namespace pitomba {

    class Timer : public iTimer, public iManagedTimer {

    private:
        TimeUnit deltaTimeFromLastFrame_ = 0;
        TimeUnit lastFrameTime_ = now();
        TimeUnit elapsedTime_ = 0;
        bool paused_ = true;

    public:
        Timer() = default;
        ~Timer() final = default;

        // Inherited via iTimer
        float fps() const override;
        TimeUnit elapsedTime() const override;
        TimeUnit delta() const override;

        // Inherited via iManagedTimer
        void reset() override;
        void tick() override;
        void start() override;
        void pause() override;
        void resume() override;
    };

}

#endif // TIMER_H_