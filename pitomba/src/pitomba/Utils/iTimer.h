
#ifndef I_TIMER_H_
#define I_TIMER_H_

#include "Utils.h"


namespace pitomba {

    class iTimer {

    public:
        virtual ~iTimer() = default;

        virtual float fps() const = 0;
        virtual TimeUnit elapsedTime() const = 0;
        virtual TimeUnit delta() const = 0;
    };

}

#endif // I_TIMER_H_