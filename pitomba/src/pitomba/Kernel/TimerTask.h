#ifndef TIMER_TASK_H_
#define TIMER_TASK_H_

#include "Task.h"
#include "../Utils/Timer.h"
#include "../Utils/Singleton.h"


namespace pitomba {

    class TimerTask : public Task, public Singleton<TimerTask> {
    private:
        Timer timer_;

    protected:
        void onStart() final;
        void onPause() final;
        void onUpdate() final;
        void onResume() final;
        void onStop() final;

    public:
        TimerTask(const unsigned int priority);
        virtual ~TimerTask();

    };

}


#endif // TIMER_TASK_H_