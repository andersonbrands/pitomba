#include "RendererTask.h"
#include "../Utils/Logger.h"
#include "../Utils/Utils.h"


namespace pitomba {


    RendererTask::RendererTask(const unsigned int priority) : Task(priority) {}

    void RendererTask::onStart() {
        Logger::getInstancePtr()->debug(
            "RendererTask start!"
        );
        renderer.initialize();
    }

    void RendererTask::onUpdate() {
        // TODO remove blocking update, this will block other tasks
        renderer.fillSurface(0xff, 0x00, 0x00);
        renderer.update();
        sleep(500);
        renderer.fillSurface(0x00, 0xff, 0x00);
        renderer.update();
        sleep(500);
        renderer.fillSurface(0x00, 0x00, 0xff);
        renderer.update();
        sleep(500);
        renderer.fillSurface(0x00, 0xff, 0xff);
        renderer.update();
        sleep(500);
    }

    void RendererTask::onStop() {
        Logger::getInstancePtr()->debug(
            "RendererTask stop!"
        );
    }

}