
#include "DummyTask.h"
#include "../pitomba/Utils/Logger.h"
#include "../pitomba/Utils/Utils.h"


DummyTask::DummyTask(const unsigned int priority) : Task(priority) {

}

DummyTask::~DummyTask() {}

void DummyTask::onUpdate() {
    if (!isRunning()) return;

    Logger::getInstancePtr()->debug(
        boost::format("Dummy task: %1%") % count++
    );

    if (count >= 20) {
        stop();
    }
}
