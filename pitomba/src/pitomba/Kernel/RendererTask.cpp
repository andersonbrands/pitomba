#include "RendererTask.h"
#include "../Utils/Logger.h"


namespace pitomba {


    RendererTask::RendererTask(const unsigned int priority) : Task(priority) {}

    RendererTask::~RendererTask() {}

    void RendererTask::onStart() {
        Logger::getInstancePtr()->debug(
            "RendererTask start!"
        );
    }

    void RendererTask::onStop() {
        Logger::getInstancePtr()->debug(
            "RendererTask stop!"
        );
    }

}