#ifndef RENDERER_H_
#define RENDERER_H_

#include "Task.h"
#include "../Renderer/iRenderer.h"
#include "../EventManager/iEventManager.h"
#include "../Utils/iRng.h"
#include "../Utils/iTimer.h"
#include "../Utils/iLogger.h"
#include "../Utils/Scheduler.h"
#include "../Utils/iLocator.h"
#include "../Renderer/D3DRenderer.h"
#include <memory>
#include "../Renderer/MainWindow.h"


namespace pitomba {

    class RendererTask : public Task {

    public:
        explicit RendererTask(const unsigned int priority,
                              iLocator<iEventManager>* pEventManagerLocator,
                              iLocator<iTimer>* pTimerLocator,
                              iLocator<iRng>* pRngLocator,
                              iLocator<iLogger>* pLoggerLocator);
        ~RendererTask() final = default;

        void onInitialize() final;
        void onStart() final;
        void onUpdate() final;
        void onStop() final;

        iRenderer* getRenderer() const;

    private:
        iLocator<iEventManager>* pEventManagerLocator_;
        iLocator<iTimer>* pTimerLocator_;
        iLocator<iRng>* pRngLocator_;
        iLocator<iLogger>* pLoggerLocator_;

        Scheduler scheduler_;
        std::unique_ptr<MainWindow> pWindow_ = std::make_unique<MainWindow>(L"D3D Renderer!!!", pEventManagerLocator_);
        std::unique_ptr<iRenderer> pRenderer_ = std::make_unique<D3DRenderer>(pWindow_.get());
    };

}

#endif // RENDERER_H_
