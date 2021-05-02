#include "RendererTask.h"
#include "../Utils/Logger.h"
#include "../Utils/Utils.h"
#include "TimerTask.h"


namespace pitomba {


    RendererTask::RendererTask(const unsigned int priority) : Task(priority) {}

    void RendererTask::onInitialize() {
        renderer_.initialize();
    }

    void RendererTask::onStart() {
        Logger::getInstancePtr()->debug(
            "RendererTask start!"
        );
        std::function<void()> random_fill = [&]() {
            renderer_.fillSurface(
                rand_int(0, 255),
                rand_int(0, 255),
                rand_int(0, 255)
            );
        };
        scheduler_.setTimeout(5000, random_fill);
    }

    void RendererTask::onUpdate() {
        scheduler_.tick(TimerTask::getInstancePtr()->getDelta());
        renderer_.update();
    }

    void RendererTask::onStop() {
        Logger::getInstancePtr()->debug(
            "RendererTask stop!"
        );
    }

}