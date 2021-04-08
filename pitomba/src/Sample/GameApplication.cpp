#include "GameApplication.h"


GameApplication::GameApplication() : Application(), pDummyTask_(nullptr) {

}

GameApplication::~GameApplication() {
    if (pDummyTask_) {
        delete pDummyTask_;
        pDummyTask_ = nullptr;
    }
}

bool GameApplication::initialize() {
    bool success(true);

    pDummyTask_ = new DummyTask(10000);

    kernel_.addTask(pDummyTask_);

    return success;
}
