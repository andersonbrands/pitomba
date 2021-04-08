#ifndef GAME_APPLICATION_H_
#define GAME_APPLICATION_H_


#include "..\pitomba\Application\Application.h"

using namespace pitomba;

class GameApplication : public Application {
private:

protected:

public:
    explicit GameApplication();
    virtual ~GameApplication();

    virtual bool initialize();
};

#endif // GAME_APPLICATION_H_
