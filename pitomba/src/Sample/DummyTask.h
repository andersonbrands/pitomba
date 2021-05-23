#ifndef DUMMY_TASK_H_
#define DUMMY_TASK_H_


#include <memory>
#include "../pitomba/Kernel/Task.h"
#include "../pitomba/Renderer/Sprite/D3DSprite.h"
#include "../pitomba/EventManager/iEventManager.h"
#include "../pitomba/EventManager/EventHandler.h"
#include "../pitomba/Utils/ServiceLocator.h"


using namespace pitomba;

class DummyTask : public Task, public EventHandler {
public:
    explicit DummyTask(const unsigned int priority);
    ~DummyTask() final = default;

private:

    std::shared_ptr<iEventManager> pEventManager_ = ServiceLocator::getEventManager();
    void onUpdate() final;
    void onStart() final;

    D3DSprite sprite;

    // EventHandler interface
    void handleEvent(EventId eventId, void* pData) override;
};

#endif // DUMMY_TASK_H_ 
