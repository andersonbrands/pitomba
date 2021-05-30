#ifndef TASK_H_
#define TASK_H_

namespace pitomba {

    class Task {
    private:
        unsigned int priority_;
        bool running_ = false;
        bool finished_ = false;

        static const unsigned int TASK_MAX_PRIORITY = 0;
    protected:
        virtual void onInitialize();
        virtual void onStart();
        virtual void onPause();
        virtual void onUpdate();
        virtual void onResume();
        virtual void onStop();

    public:
        explicit Task(const unsigned int priority);
        virtual ~Task() = default;

        void initialize();
        void start();
        void pause();
        void update();
        void resume();
        void stop();

        bool isRunning() const;
        bool isFinished() const;
        unsigned int getPriority() const;

        static const unsigned int TIMER_PRIORITY = TASK_MAX_PRIORITY;
        static const unsigned int GAME_PRIORITY = 1000;
        static const unsigned int RENDERER_PRIORITY = 2000;
    };

    inline void Task::onInitialize() { /* Intentionally unimplemented... */ }
    inline void Task::onStart() { /* Intentionally unimplemented... */ }
    inline void Task::onPause() { /* Intentionally unimplemented... */ }
    inline void Task::onUpdate() { /* Intentionally unimplemented... */ }
    inline void Task::onResume() { /* Intentionally unimplemented... */ }
    inline void Task::onStop() { /* Intentionally unimplemented... */ }

    inline Task::Task(const unsigned int priority) :
        priority_(priority) {

    }

    inline void Task::initialize() {
        onInitialize();
    }

    inline void Task::start() {
        running_ = true;
        onStart();
    }

    inline void Task::pause() {
        running_ = false;
        onPause();
    }

    inline void Task::update() {
        onUpdate();
    }


    inline void Task::resume() {
        running_ = true;
        onResume();
    }

    inline void Task::stop() {
        running_ = false;
        finished_ = true;
        onStop();
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
