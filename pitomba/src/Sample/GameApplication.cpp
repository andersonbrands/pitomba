#include "GameApplication.h"
#include "../pitomba/Kernel/TimerTask.h"
#include "../pitomba/Kernel/RendererTask.h"

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


    assert(RendererTask::getInstancePtr());
    kernel_.addTask(RendererTask::getInstancePtr());

    return success;
}

void GameApplication::createSingletons() {
    new TimerTask(Task::TIMER_PRIORITY);
    new RendererTask(Task::RENDERER_PRIORITY);
}

void GameApplication::destroySingletons() {
    assert(TimerTask::getInstancePtr());
    delete TimerTask::getInstancePtr();

    assert(RendererTask::getInstancePtr());
    delete RendererTask::getInstancePtr();
}
