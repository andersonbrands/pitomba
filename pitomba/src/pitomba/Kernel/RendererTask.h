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
#include "../Renderer/MainWindow.h"


namespace pitomba {

    class RendererTask : public Task {

    public:
        explicit RendererTask(const unsigned int priority);
        ~RendererTask() final = default;

        void onInitialize() final;
        void onStart() final;
        void onUpdate() final;
        void onStop() final;

        iRenderer* getRenderer() const;

    private:
        Scheduler scheduler_;
        std::unique_ptr<MainWindow> pWindow_ = std::make_unique<MainWindow>(L"D3D Renderer!!!");
        std::unique_ptr<iRenderer> pRenderer_ = std::make_unique<D3DRenderer>(pWindow_.get());

        iEventManager* pEventManager_ = ServiceLocator::getEventManager();
        iRng* pRng_ = ServiceLocator::getRng();
        iTimer* pTimer_ = ServiceLocator::getTimer();
    };

}

#endif // RENDERER_H_
