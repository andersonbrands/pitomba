#include "GameApplication.h"
#include "../pitomba/Kernel/TimerTask.h"
#include "../pitomba/Kernel/RendererTask.h"
#include "../pitomba/EventManager/EventManager.h"
#include "../pitomba/Utils/Rng.h"

using namespace pitomba;


GameApplication::GameApplication() : Application() {

}

GameApplication::~GameApplication() {
    terminate();
}

bool GameApplication::initialize() {
    bool success(true);

    createSingletons();

    EventManager::getInstancePtr()->registerEvent(ev::id::APPLICATION_QUIT);

    EventManager::getInstancePtr()->attachEvent(ev::id::APPLICATION_QUIT, *this);

    pDummyTask_ = std::make_unique<DummyTask>(10000);
    addTask(pDummyTask_.get());

    assert(TimerTask::getInstancePtr());
    addTask(TimerTask::getInstancePtr());

    assert(RendererTask::getInstancePtr());
    addTask(RendererTask::getInstancePtr());

    return success;
}

void GameApplication::terminate() {
    EventManager::getInstancePtr()->unregisterEvent(ev::id::APPLICATION_QUIT);
    destroySingletons();
}

void GameApplication::handleEvent(EventId eventId, void* pData) {
    if (eventId == ev::id::APPLICATION_QUIT) {
        killAllTasks();
    }
}

void GameApplication::createSingletons() {
    new EventManager();
    new Rng();
    new TimerTask(Task::TIMER_PRIORITY);
    new RendererTask(Task::RENDERER_PRIORITY);
}

void GameApplication::destroySingletons() {
    assert(RendererTask::getInstancePtr());
    delete RendererTask::getInstancePtr();

    assert(TimerTask::getInstancePtr());
    delete TimerTask::getInstancePtr();

    assert(Rng::getInstancePtr());
    delete Rng::getInstancePtr();

    assert(EventManager::getInstancePtr());
    delete EventManager::getInstancePtr();
}
