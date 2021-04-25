#ifndef TASK_H_
#define TASK_H_

namespace pitomba {

    class Task {
    private:
        unsigned int priority_;
        bool running_;
        bool finished_;

    protected:

    public:
        explicit Task(const unsigned int priority);
        virtual ~Task();

        virtual void start();
        virtual void pause();
        virtual void update() = 0;
        virtual void resume();
        virtual void stop();

        bool isRunning() const;
        bool isFinished() const;
        unsigned int getPriority() const;

        static const unsigned int MAX_PRIORITY = 0;
        static const unsigned int TIMER_PRIORITY = MAX_PRIORITY;
        static const unsigned int RENDERER_PRIORITY = 1000;
    };

    inline Task::Task(const unsigned int priority) :
        priority_(priority), running_(false), finished_(false) {

    }

    inline Task::~Task() {}

    inline void Task::start() {
        running_ = true;
    }

    inline void Task::pause() {
        running_ = false;
    }

    inline void Task::resume() {
        running_ = true;
    }

    inline void Task::stop() {
        running_ = false;
        finished_ = true;
    }

    inline bool Task::isRunning() const {
        return running_;
    }

    inline bool Task::isFinished() const {
        return finished_;
    }

    inline unsigned int Task::getPriority() const {
        return priority_;
    }
}

#endif // TASK_H_
