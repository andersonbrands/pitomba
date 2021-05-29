
#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <functional>
#include "Utils.h"

namespace pitomba {

    class Scheduler {
    public:
        Scheduler() = default;
        virtual ~Scheduler() = default;

        void tick(TimeUnit);
        void setInterval(int, std::function<void()> const&, int = 0, int = 0);
        void setTimeout(int, std::function<void()> const&);

    private:
        std::function<void()> func_;
        TimeUnit interval_ = 0;
        TimeUnit timeout_ = 0;
        TimeUnit counter_ = 0;
        unsigned int times_ = 0;
        unsigned int timesCounter_ = 0;

        void trigger();
    };

}

#endif // SCHEDULER_H_