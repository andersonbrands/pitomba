#include "GameApplication.h"

using namespace pitomba;

GameApplication::GameApplication() :
    Application(), pDummyTask_(nullptr), pTimerTask_(nullptr) {

}

GameApplication::~GameApplication() {
    if (pDummyTask_) {
        delete pDummyTask_;
        pDummyTask_ = nullptr;
    }
    if (pTimerTask_) {
        delete pTimerTask_;
        pTimerTask_ = nullptr;
    }
}

bool GameApplication::initialize() {
    bool success(true);

    pDummyTask_ = new DummyTask(10000);
    kernel_.addTask(pDummyTask_);

    pTimerTask_ = new TimerTask(Task::TIMER_PRIORITY);
    kernel_.addTask(pTimerTask_);

    return success;
}
