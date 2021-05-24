#include "GameApplication.h"
#include "../pitomba/Kernel/TimerTask.h"
#include "../pitomba/Kernel/RendererTask.h"
#include "../pitomba/EventManager/EventManager.h"
#include "../pitomba/Renderer/Texture/TextureManager.h"
#include "../pitomba/Utils/Rng.h"
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
    pEventManager_->registerEvent(ev::id::CREATE_D3D_VERTEX_BUFFER);
    pEventManager_->registerEvent(ev::id::CREATE_D3D_TEXTURE);
    pEventManager_->registerEvent(ev::id::RENDER_TEXTURE);

    pEventManager_->registerEvent(ev::id::PRE_RENDER);
    pEventManager_->registerEvent(ev::id::RENDER);
    pEventManager_->registerEvent(ev::id::POST_RENDER);

    pEventManager_->registerEvent(ev::id::SETUP_VIEW_MATRIX);
    pEventManager_->registerEvent(ev::id::SETUP_LH_ORTHOGONAL_PROJECTION_MATRIX);

    pEventManager_->attachEvent(ev::id::APPLICATION_QUIT, *this);

    pDummyTask_ = std::make_unique<DummyTask>(10000);
    addTask(pDummyTask_.get());

    addTask(pTimerTask_.get());

    assert(RendererTask::getInstancePtr());
    addTask(RendererTask::getInstancePtr());

    return success;
}

void GameApplication::terminate() {
    pEventManager_->unregisterEvent(ev::id::APPLICATION_QUIT);
    pEventManager_->unregisterEvent(ev::id::CREATE_D3D_VERTEX_BUFFER);
    pEventManager_->unregisterEvent(ev::id::CREATE_D3D_TEXTURE);
    pEventManager_->unregisterEvent(ev::id::RENDER_TEXTURE);
    pEventManager_->unregisterEvent(ev::id::PRE_RENDER);
    pEventManager_->unregisterEvent(ev::id::RENDER);
    pEventManager_->unregisterEvent(ev::id::POST_RENDER);
    pEventManager_->unregisterEvent(ev::id::SETUP_VIEW_MATRIX);
    pEventManager_->unregisterEvent(ev::id::SETUP_LH_ORTHOGONAL_PROJECTION_MATRIX);
    destroySingletons();
}

void GameApplication::handleEvent(EventId eventId, void* pData) {
    if (eventId == ev::id::APPLICATION_QUIT) {
        killAllTasks();
    }
}

void GameApplication::createServices() {
    pEventManager_ = std::make_shared<EventManager>();
    ServiceLocator::provide(pEventManager_.get());

    pRng_ = std::make_shared<Rng>();
    ServiceLocator::provide(pRng_.get());

    pTimerTask_ = std::make_unique<TimerTask>(Task::TIMER_PRIORITY);
    ServiceLocator::provide(pTimerTask_->getTimer());
}

void GameApplication::createSingletons() {
    new RendererTask(Task::RENDERER_PRIORITY);
    new TextureManager(L"data/textures/");
}

void GameApplication::destroySingletons() {
    assert(TextureManager::getInstancePtr());
    delete TextureManager::getInstancePtr();

    assert(RendererTask::getInstancePtr());
    delete RendererTask::getInstancePtr();
}
