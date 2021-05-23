#ifndef RENDERER_H_
#define RENDERER_H_

#include "Task.h"
#include "../Utils/Singleton.h"
#include "../Renderer/iRenderer.h"
#include "../EventManager/iEventManager.h"
#include "../Utils/Scheduler.h"
#include "../Utils/ServiceLocator.h"
#include <memory>

namespace pitomba {

    class RendererTask : public Task, public Singleton<RendererTask> {

    public:
        explicit RendererTask(const unsigned int priority);
        ~RendererTask() final;

        void onInitialize() final;
        void onStart() final;
        void onUpdate() final;
        void onStop() final;

    private:
        Scheduler scheduler_;
        iRenderer* pRenderer_ = nullptr;
        std::shared_ptr<iEventManager> pEventManager_ = ServiceLocator::getEventManager();
    };

}

#endif // RENDERER_H_
