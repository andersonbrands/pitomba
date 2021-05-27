#include "GameApplication.h"
#include "../pitomba/EventManager/EventManager.h"
#include "../pitomba/Renderer/Texture/TextureManager.h"
#include "../pitomba/Utils/Rng.h"
#include "../pitomba/Utils/Logger.h"
#include "../pitomba/Utils/ServiceLocator.h"

using namespace pitomba;


GameApplication::GameApplication() : Application() {

}

GameApplication::~GameApplication() {
    terminate();
}

bool GameApplication::initialize() {
    bool success(true);

    createServices();
    createSingletons();

    pEventManager_->registerEvent(ev::id::APPLICATION_QUIT);

    pEventManager_->registerEvent(ev::id::PRE_RENDER);
    pEventManager_->registerEvent(ev::id::RENDER);
    pEventManager_->registerEvent(ev::id::POST_RENDER);

    pEventManager_->attachEvent(ev::id::APPLICATION_QUIT, *this);

    pDummyTask_ = std::make_unique<DummyTask>(10000);
    addTask(pDummyTask_.get());

    addTask(pTimerTask_.get());

    addTask(pRendererTask_.get());

    return success;
}

void GameApplication::terminate() {
    pEventManager_->unregisterEvent(ev::id::APPLICATION_QUIT);
    pEventManager_->unregisterEvent(ev::id::PRE_RENDER);
    pEventManager_->unregisterEvent(ev::id::RENDER);
    pEventManager_->unregisterEvent(ev::id::POST_RENDER);
    destroySingletons();
}

void GameApplication::handleEvent(EventId eventId, void* pData) {
    if (eventId == ev::id::APPLICATION_QUIT) {
        killAllTasks();
    }
}

void GameApplication::createServices() {
    pLogger_ = std::make_unique<Logger>();
    ServiceLocator::provide(pLogger_.get());

    pEventManager_ = std::make_unique<EventManager>();
    ServiceLocator::provide(pEventManager_.get());

    pRng_ = std::make_unique<Rng>();
    ServiceLocator::provide(pRng_.get());

    pTimerTask_ = std::make_unique<TimerTask>(Task::TIMER_PRIORITY);
    ServiceLocator::provide(pTimerTask_->getTimer());

    pRendererTask_ = std::make_unique<RendererTask>(Task::RENDERER_PRIORITY);
    ServiceLocator::provide(pRendererTask_->getRenderer());

    pTextureManager_ = std::make_unique<TextureManager>(L"data/textures/");
    ServiceLocator::provide(pTextureManager_.get());
}

void GameApplication::createSingletons() {

}

void GameApplication::destroySingletons() {

}
