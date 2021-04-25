#ifndef GAME_APPLICATION_H_
#define GAME_APPLICATION_H_


#include "../pitomba/Application/Application.h"
#include "DummyTask.h"

using namespace pitomba;


class GameApplication : public Application {
private:
    std::unique_ptr<DummyTask> pDummyTask_ = nullptr;

    void createSingletons();
    void destroySingletons();

public:
    explicit GameApplication();
    ~GameApplication() final;

    bool initialize() final;
};

#endif // GAME_APPLICATION_H_

