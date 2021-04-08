#ifndef TASK_H_
#define TASK_H_

namespace pitomba {

    class Task {
    private:
        unsigned int priority_;
        bool canKill_;
        bool suspended_;

    protected:

    public:
        explicit Task(const unsigned int priority);
        virtual ~Task();

        virtual bool start() = 0;
        virtual void onSuspend() = 0;
        virtual void update() = 0;
        virtual void onResume() = 0;
        virtual void stop() = 0;

        void setSuspended(const bool suspended);
        bool isSuspended() const;
        void setCanKill(const bool canKill);
        bool canKill() const;
        unsigned int getPriority() const;

        static const unsigned int MAX_PRIORITY = 0;
    };

    inline Task::Task(const unsigned int priority) : priority_(priority), canKill_(false), suspended_(false) {

    }

    inline Task::~Task() {}

    inline void Task::setSuspended(const bool suspended) {
        suspended_ = suspended;
    }

    inline bool Task::isSuspended() const {
        return suspended_;
    }

    inline void Task::setCanKill(const bool canKill) {
        canKill_ = canKill;
    }

    inline bool Task::canKill() const {
        return canKill_;
    }

    inline unsigned int	Task::getPriority() const {
        return priority_;
    }
}

#endif // TASK_H_
