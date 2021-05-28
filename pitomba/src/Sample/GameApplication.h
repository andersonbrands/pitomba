#ifndef GAME_APPLICATION_H_
#define GAME_APPLICATION_H_


#include <memory>
#include "../pitomba/Application/Application.h"
#include "../pitomba/EventManager/EventHandler.h"
#include "../pitomba/EventManager/iEventManager.h"
#include "../pitomba/Utils/ServiceLocator.h"
#include "../pitomba/Utils/iRng.h"
#include "../pitomba/Utils/iLogger.h"
#include "../pitomba/Kernel/TimerTask.h"
#include "../pitomba/Kernel/RendererTask.h"
#include "DummyTask.h"

using namespace pitomba;


class GameApplication : public Application, public EventHandler {
private:
    std::unique_ptr<ServiceLocator> pLocator_ = std::make_unique<ServiceLocator>();

    iLocator<iRng>* pRngLocator_ = pLocator_.get();
    iLocator<iTimer>* pTimerLocator_ = pLocator_.get();
    iLocator<iRenderer>* pRendererLocator_ = pLocator_.get();
    iLocator<iEventManager>* pEventManagerLocator_ = pLocator_.get();
    iLocator<iLogger>* pLoggerLocator_ = pLocator_.get();
    iLocator<iTextureManager>* pTextureManagerLocator_ = pLocator_.get();

    std::unique_ptr<iRng> pRng_ = nullptr;
    std::unique_ptr<iLogger> pLogger_ = nullptr;
    std::unique_ptr<iEventManager> pEventManager_ = nullptr;
    std::unique_ptr<iTextureManager> pTextureManager_ = nullptr;

    std::unique_ptr<DummyTask> pDummyTask_ = nullptr;
    std::unique_ptr<TimerTask> pTimerTask_ = nullptr;
    std::unique_ptr<RendererTask> pRendererTask_ = nullptr;


    void createServices();

public:
    explicit GameApplication();
    ~GameApplication() final;

    bool initialize() final;
    void terminate() final;

    void handleEvent(EventId eventId, void* pData) final;
};

#endif // GAME_APPLICATION_H_
