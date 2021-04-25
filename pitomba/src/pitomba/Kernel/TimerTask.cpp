
#include "TimerTask.h"
#include "../Utils/Logger.h"
#include "RendererTask.h"

namespace pitomba {

    TimerTask::TimerTask(const unsigned int priority) : Task(priority) {}

    TimerTask::~TimerTask() {}

    void TimerTask::start() {
        Task::start();
        timer_.start();
    }

    void TimerTask::pause() {
        Task::pause();
        timer_.pause();
    }

    void TimerTask::update() {
        timer_.tick();

        auto gameTime = toSeconds(timer_.getElapsedTime());
        Logger::getInstancePtr()->debug(
            boost::format("GameTime (s): %1%\tFPS: %2%") % gameTime % timer_.getFPS()
        );
        sleep(1);

        // TODO remove
        if (timer_.getElapsedTime() >= 300) {
            stop();

            // TODO remove when another way to stop Renderer Task is implemented
            RendererTask::getInstancePtr()->stop();
        }
    }

    void TimerTask::resume() {
        Task::resume();
        timer_.resume();
    }

    void TimerTask::stop() {
        Task::stop();
        timer_.pause();
    }

}