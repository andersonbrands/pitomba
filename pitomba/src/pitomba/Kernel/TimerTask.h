#ifndef TIMER_TASK_H_
#define TIMER_TASK_H_

#include "Task.h"
#include "../Utils/Timer.h"
#include "../Utils/Singleton.h"
#include <functional>


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
        explicit TimerTask(const unsigned int priority);
        ~TimerTask() final = default;

        TimeUnit getDelta() const;
    };

}


#endif // TIMER_TASK_H_