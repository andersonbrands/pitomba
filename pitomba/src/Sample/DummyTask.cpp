
#include "DummyTask.h"
#include "../pitomba/Utils/Logger.h"
#include "../pitomba/Utils/Utils.h"


DummyTask::DummyTask(const unsigned int priority) : Task(priority) {

}


void DummyTask::onUpdate() {
    if (!isRunning()) return;

    count++;
    Logger::getInstancePtr()->debug(
        boost::format("Dummy task: %1%") % count
    );

    if (count >= 20) {
        stop();
    }
}
