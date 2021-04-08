
#include "DummyTask.h"
#include "..\pitomba\Utils\Logger.h"
#include <string>


DummyTask::DummyTask(const unsigned int priority) : Task(priority) {

}

DummyTask::~DummyTask() {}

bool DummyTask::start() {
    return true;
}

void DummyTask::onSuspend() {
    setSuspended(true);
}

void DummyTask::update() {
    if (isSuspended()) return;

    Logger::getInstancePtr()->debug(std::to_string(count++));

    if (count >= 10) {
        setCanKill(true);
    }
}

void DummyTask::onResume() {
    setSuspended(false);
}

void DummyTask::stop() {

}
