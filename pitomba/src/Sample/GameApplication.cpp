#include "GameApplication.h"
#include "../pitomba/Kernel/TimerTask.h"

using namespace pitomba;


GameApplication::GameApplication() :
    Application(), pDummyTask_(nullptr) {

}

GameApplication::~GameApplication() {
    if (pDummyTask_) {
        delete pDummyTask_;
        pDummyTask_ = nullptr;
    }
}

bool GameApplication::initialize() {
    bool success(true);

    createSingletons();

    pDummyTask_ = new DummyTask(10000);
    kernel_.addTask(pDummyTask_);

    assert(TimerTask::getInstancePtr());
    kernel_.addTask(TimerTask::getInstancePtr());

    return success;
}

void GameApplication::createSingletons() {
    new TimerTask(Task::TIMER_PRIORITY);
}

void GameApplication::destroySingletons() {
    assert(TimerTask::getInstancePtr());
    delete TimerTask::getInstancePtr();
}
