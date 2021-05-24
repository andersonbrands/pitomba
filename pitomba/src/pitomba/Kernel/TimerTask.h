#ifndef TIMER_TASK_H_
#define TIMER_TASK_H_

#include "Task.h"
#include "../Utils/iTimer.h"
#include "../Utils/iManagedTimer.h"
#include "../Utils/Timer.h"
#include <memory>


namespace pitomba {

    class TimerTask : public Task {
    public:
        explicit TimerTask(const unsigned int priority);
        ~TimerTask() final = default;

        iTimer* getTimer() const;

    protected:
        void onStart() final;
        void onPause() final;
        void onUpdate() final;
        void onResume() final;
        void onStop() final;

    private:
        std::unique_ptr<Timer> pConcreteTimer_ = std::make_unique<Timer>();
        iTimer* pTimer_ = pConcreteTimer_.get();
        iManagedTimer* pManagedTimer_ = pConcreteTimer_.get();
    };

}


#endif // TIMER_TASK_H_