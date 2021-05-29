#ifndef TIMER_TASK_H_
#define TIMER_TASK_H_

#include "Task.h"
#include "../Utils/iTimer.h"
#include "../Utils/iManagedTimer.h"
#include <memory>


namespace pitomba {

    class TimerTask : public Task {
    public:
        explicit TimerTask(const unsigned int priority, iTimer* pTimer, iManagedTimer* pManagedTimer);
        ~TimerTask() final = default;

        iTimer* getTimer() const;

    protected:
        void onStart() final;
        void onPause() final;
        void onUpdate() final;
        void onResume() final;
        void onStop() final;

    private:
        iTimer* pTimer_;
        iManagedTimer* pManagedTimer_;
    };

}


#endif // TIMER_TASK_H_