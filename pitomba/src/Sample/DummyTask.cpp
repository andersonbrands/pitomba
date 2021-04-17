
#include "DummyTask.h"
#include "..\pitomba\Utils\Logger.h"
#include <boost\format.hpp>
#include "../pitomba/Utils/Utils.h"


DummyTask::DummyTask(const unsigned int priority) : Task(priority) {

}

DummyTask::~DummyTask() {}

bool DummyTask::start() {
    timer_.start();
    return true;
}

void DummyTask::onSuspend() {
    setSuspended(true);
}

void DummyTask::update() {
    if (isSuspended()) return;

    timer_.tick();

    auto gameTime = toSeconds(timer_.getElapsedTime());
    Logger::getInstancePtr()->debug(boost::format("GameTime (s): %1%\tFPS: %2%") % gameTime % timer_.getFPS());
    sleep(1);

    if (count++ >= 200) {
        setCanKill(true);
    }
}

void DummyTask::onResume() {
    setSuspended(false);
}

void DummyTask::stop() {

}
