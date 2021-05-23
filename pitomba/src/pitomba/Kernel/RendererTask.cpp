#include "RendererTask.h"
#include "../Utils/Logger.h"
#include "../Utils/Utils.h"
#include "TimerTask.h"
#include "../Renderer/D3DRenderer.h"


namespace pitomba {

    RendererTask::RendererTask(const unsigned int priority)
        : Task(priority), pRenderer_(new D3DRenderer(L"D3D Renderer!!!")) {}

    RendererTask::~RendererTask() {
        if (pRenderer_) {
            delete pRenderer_;
            pRenderer_ = nullptr;
        }
    }

    void RendererTask::onInitialize() {
        pRenderer_->initialize();
    }

    void RendererTask::onStart() {
        Logger::getInstancePtr()->debug(
            "RendererTask start!"
        );
        pRenderer_->start();
        std::function<void()> random_fill = [&]() {
            pRenderer_->fillSurface(rand_color_RGB());
        };
        scheduler_.setInterval(1000, random_fill);
    }

    void RendererTask::onUpdate() {
        if (pRenderer_->preRender()) {
            pEventManager_->sendEvent(ev::id::PRE_RENDER);

            pRenderer_->render();

            pEventManager_->sendEvent(ev::id::RENDER);
            scheduler_.tick(TimerTask::getInstancePtr()->getDelta()); // TODO handle Render event

            pRenderer_->postRender();
            pEventManager_->sendEvent(ev::id::POST_RENDER);
        }

    }

    void RendererTask::onStop() {
        Logger::getInstancePtr()->debug(
            "RendererTask stop!"
        );
    }

}