#ifndef DUMMY_TASK_H_
#define DUMMY_TASK_H_


#include "../pitomba/Kernel/Task.h"
#include "../pitomba/Renderer/Sprite/D3DSprite.h"
#include "../pitomba/EventManager/EventHandler.h"


using namespace pitomba;

class DummyTask : public Task, public EventHandler {
public:
    explicit DummyTask(const unsigned int priority);
    ~DummyTask() final = default;

private:
    void onUpdate() final;
    void onStart() final;

    D3DSprite sprite;

    // EventHandler interface
    virtual void handleEvent(EventId eventId, void* pData) override;
};

#endif // DUMMY_TASK_H_ 
