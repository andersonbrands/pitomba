#ifndef RENDERER_H_
#define RENDERER_H_

#include "Task.h"
#include "../Utils/Singleton.h"
#include "../Renderer/iRenderer.h"
#include "../EventManager/iEventManager.h"
#include "../Utils/iRng.h"
#include "../Utils/iTimer.h"
#include "../Utils/Scheduler.h"
#include "../Utils/ServiceLocator.h"
#include "../Renderer/D3DRenderer.h"
#include <memory>


namespace pitomba {

    class RendererTask : public Task, public Singleton<RendererTask> {

    public:
        explicit RendererTask(const unsigned int priority);
        ~RendererTask() final = default;

        void onInitialize() final;
        void onStart() final;
        void onUpdate() final;
        void onStop() final;

    private:
        Scheduler scheduler_;
        std::unique_ptr<iRenderer> pRenderer_ = std::make_unique<D3DRenderer>(L"D3D Renderer!!!");
        iEventManager* pEventManager_ = ServiceLocator::getEventManager();
        iRng* pRng_ = ServiceLocator::getRng();
        iTimer* pTimer_ = ServiceLocator::getTimer();
    };

}

#endif // RENDERER_H_
