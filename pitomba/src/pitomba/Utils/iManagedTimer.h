
#ifndef I_MANAGED_TIMER_H_
#define I_MANAGED_TIMER_H_


namespace pitomba {

    class iManagedTimer {

    public:
        virtual ~iManagedTimer() = default;

        virtual void reset() = 0;
        virtual void tick() = 0;
        virtual void start() = 0;
        virtual void pause() = 0;
        virtual void resume() = 0;

    };

}

#endif // I_MANAGED_TIMER_H_
