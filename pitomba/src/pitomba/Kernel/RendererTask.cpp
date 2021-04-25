#include "RendererTask.h"
#include "../Utils/Logger.h"


namespace pitomba {


    RendererTask::RendererTask(const unsigned int priority) : Task(priority) {}

    RendererTask::~RendererTask() {}

    void RendererTask::start() {
        Task::start();
        Logger::getInstancePtr()->debug(
            "RendererTask start!"
        );
    }

    void RendererTask::pause() {
        Task::pause();
    }

    void RendererTask::update() {}

    void RendererTask::resume() {
        Task::resume();
    }

    void RendererTask::stop() {
        Task::stop();
        Logger::getInstancePtr()->debug(
            "RendererTask stop!"
        );
    }

}