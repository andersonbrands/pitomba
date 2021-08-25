#include "GameApplication.h"
#include <pitomba/Utils/Logger.h>
#include <pitomba/Utils/Rng.h>
#include <pitomba/EventManager/EventManager.h>


using namespace pitomba;
using namespace std;


GameApplication::GameApplication() : Application() {
    pLogger_ = make_unique<Logger>();
    pEventManager_ = make_unique<EventManager>();
    pRng_ = make_unique<Rng>();
    pTimerTask_ = make_unique<TimerTask>(Task::TIMER_PRIORITY, pTimer_, pManagedTimer_);
    pRendererTask_ = make_unique<RendererTask>(Task::RENDERER_PRIORITY, pEventManagerLocator_, pTimerLocator_, pRngLocator_, pLoggerLocator_);
    pInputTask_ = make_unique<InputTask>(Task::INPUT_PRIORITY, pEventManagerLocator_, pRendererTask_->getWindowProvider());
    pDummyTask_ = make_unique<DummyTask>(Task::GAME_PRIORITY, pEventManagerLocator_, pRendererLocator_, pRngLocator_, pTimerLocator_, pTextureContainerLocator_, pTextureDirProvider_);
}

GameApplication::~GameApplication() {
    terminate();
}

bool GameApplication::initialize() {
    bool success(true);

    provideServices();

    pEventManager_->registerEvent(ev::id::APPLICATION_QUIT);
    pEventManager_->registerEvent(ev::id::PRE_RENDER);
    pEventManager_->registerEvent(ev::id::RENDER);
    pEventManager_->registerEvent(ev::id::POST_RENDER);

    pEventManager_->attachEvent(ev::id::APPLICATION_QUIT, *this);

    addTask(pDummyTask_.get());
    addTask(pTimerTask_.get());
    addTask(pRendererTask_.get());
    addTask(pInputTask_.get());

    return success;
}

void GameApplication::terminate() {
    pEventManager_->unregisterEvent(ev::id::APPLICATION_QUIT);
    pEventManager_->unregisterEvent(ev::id::PRE_RENDER);
    pEventManager_->unregisterEvent(ev::id::RENDER);
    pEventManager_->unregisterEvent(ev::id::POST_RENDER);
}

void GameApplication::handleEvent(EventId eventId, void* pData) {
    if (eventId == ev::id::APPLICATION_QUIT) {
        killAllTasks();
    }
}

void GameApplication::provideServices() {
    pLoggerLocator_->provide(pLogger_.get());
    pEventManagerLocator_->provide(pEventManager_.get());
    pRngLocator_->provide(pRng_.get());
    pTimerLocator_->provide(pTimerTask_->getTimer());
    pRendererLocator_->provide(pRendererTask_->getRenderer());
    pTextureContainerLocator_->provide(pTextureContainer_);
}
