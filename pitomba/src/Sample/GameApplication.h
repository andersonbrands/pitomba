#ifndef GAME_APPLICATION_H_
#define GAME_APPLICATION_H_


#include "..\pitomba\Application\Application.h"
#include "DummyTask.h"

using namespace pitomba;


class GameApplication : public Application {
private:
    DummyTask* pDummyTask_;

protected:

public:
    explicit GameApplication();
    virtual ~GameApplication();

    virtual bool initialize();
};

#endif // GAME_APPLICATION_H_
