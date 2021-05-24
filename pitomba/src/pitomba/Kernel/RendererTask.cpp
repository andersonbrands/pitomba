#include "RendererTask.h"
#include "../Utils/Logger.h"
#include "../Utils/Utils.h"
#include "TimerTask.h"


namespace pitomba {

    RendererTask::RendererTask(const unsigned int priority)
        : Task(priority) {}

    void RendererTask::onInitialize() {
        pWindow_->initialize();
        pRenderer_->initialize();
    }

    void RendererTask::onStart() {
        Logger::getInstancePtr()->debug(
            "RendererTask start!"
        );
        pWindow_->start();
        pRenderer_->start();
        std::function<void()> random_fill = [&]() {
            pRenderer_->fillSurface(rand_color_RGB(*pRng_));
        };
        scheduler_.setInterval(1000, random_fill);
    }

    void RendererTask::onUpdate() {
        pWindow_->update();
        if (pRenderer_->preRender()) {
            pEventManager_->sendEvent(ev::id::PRE_RENDER);

            pRenderer_->render();

            pEventManager_->sendEvent(ev::id::RENDER);
            scheduler_.tick(pTimer_->delta()); // TODO handle Render event

            pRenderer_->postRender();
            pEventManager_->sendEvent(ev::id::POST_RENDER);
        }

    }

    void RendererTask::onStop() {
        Logger::getInstancePtr()->debug(
            "RendererTask stop!"
        );
    }

    iRenderer* RendererTask::getRenderer() const {
        return pRenderer_.get();
    }

}