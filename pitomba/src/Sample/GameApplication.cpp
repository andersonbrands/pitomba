#include "GameApplication.h"
#include "../pitomba/Kernel/TimerTask.h"
#include "../pitomba/Kernel/RendererTask.h"

using namespace pitomba;


GameApplication::GameApplication() : Application() {

}

GameApplication::~GameApplication() {
    destroySingletons();
}

bool GameApplication::initialize() {
    bool success(true);

    createSingletons();

    pDummyTask_ = std::make_unique<DummyTask>(10000);
    addTask(pDummyTask_.get());

    assert(TimerTask::getInstancePtr());
    addTask(TimerTask::getInstancePtr());

    assert(RendererTask::getInstancePtr());
    addTask(RendererTask::getInstancePtr());

    return success;
}

void GameApplication::createSingletons() {
    new TimerTask(Task::TIMER_PRIORITY);
    new RendererTask(Task::RENDERER_PRIORITY);
}

void GameApplication::destroySingletons() {
    assert(RendererTask::getInstancePtr());
    delete RendererTask::getInstancePtr();

    assert(TimerTask::getInstancePtr());
    delete TimerTask::getInstancePtr();
}
