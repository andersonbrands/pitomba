#ifndef TIMER_TASK_H_
#define TIMER_TASK_H_

#include "Task.h"
#include "../Utils/Timer.h"
#include "../Utils/Singleton.h"


namespace pitomba {

    class TimerTask : public Task, public Singleton<TimerTask> {
    private:
        Timer timer_;
    public:
        TimerTask(const unsigned int priority);
        virtual ~TimerTask();

        virtual void start();
        virtual void pause();
        virtual void update();
        virtual void resume();
        virtual void stop();
    };

}


#endif // TIMER_TASK_H_