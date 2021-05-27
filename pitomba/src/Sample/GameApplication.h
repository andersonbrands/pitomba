#ifndef GAME_APPLICATION_H_
#define GAME_APPLICATION_H_


#include <memory>
#include "../pitomba/Application/Application.h"
#include "../pitomba/EventManager/EventHandler.h"
#include "../pitomba/EventManager/iEventManager.h"
#include "../pitomba/Utils/iRng.h"
#include "../pitomba/Utils/iLogger.h"
#include "../pitomba/Kernel/TimerTask.h"
#include "../pitomba/Kernel/RendererTask.h"
#include "DummyTask.h"

using namespace pitomba;


class GameApplication : public Application, public EventHandler {
private:
    std::unique_ptr<iLogger> pLogger_ = nullptr;

    std::unique_ptr<iEventManager> pEventManager_ = nullptr;

    std::unique_ptr<DummyTask> pDummyTask_ = nullptr;
    std::unique_ptr<TimerTask> pTimerTask_ = nullptr;
    std::unique_ptr<RendererTask> pRendererTask_ = nullptr;

    std::unique_ptr<iRng> pRng_ = nullptr;
    std::unique_ptr<iTextureManager> pTextureManager_ = nullptr;

    void createServices();
    void createSingletons();
    void destroySingletons();

public:
    explicit GameApplication();
    ~GameApplication() final;

    bool initialize() final;
    void terminate() final;

    void handleEvent(EventId eventId, void* pData) final;
};

#endif // GAME_APPLICATION_H_
