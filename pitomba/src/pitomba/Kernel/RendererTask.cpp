#include "RendererTask.h"
#include "../Utils/Logger.h"
#include "../Utils/Utils.h"
#include "TimerTask.h"


namespace pitomba {

    RendererTask::RendererTask(const unsigned int priority,
                               iLocator<iEventManager>* pEventManagerLocator,
                               iLocator<iTimer>* pTimerLocator,
                               iLocator<iRng>* pRngLocator,
                               iLocator<iLogger>* pLoggerLocator)
        : Task(priority),
        pEventManagerLocator_(pEventManagerLocator),
        pTimerLocator_(pTimerLocator),
        pRngLocator_(pRngLocator),
        pLoggerLocator_(pLoggerLocator) {}

    void RendererTask::onInitialize() {
        pWindow_->initialize();
        pRenderer_->initialize();
    }

    void RendererTask::onStart() {
        pLoggerLocator_->get()->debug(
            "RendererTask start!"
        );
        pWindow_->start();
        pRenderer_->start();
        std::function<void()> random_fill = [this]() {
            pRenderer_->fillSurface(rand_color_RGB(*pRngLocator_->get()));
        };
        scheduler_.setInterval(1000, random_fill);
    }

    void RendererTask::onUpdate() {
        pWindow_->update();
        if (pRenderer_->preRender()) {
            pEventManagerLocator_->get()->sendEvent(ev::id::PRE_RENDER);

            pRenderer_->render();

            pEventManagerLocator_->get()->sendEvent(ev::id::RENDER);
            scheduler_.tick(pTimerLocator_->get()->delta()); // TODO handle Render event

            pRenderer_->postRender();
            pEventManagerLocator_->get()->sendEvent(ev::id::POST_RENDER);
        }

    }

    void RendererTask::onStop() {
        pLoggerLocator_->get()->debug(
            "RendererTask stop!"
        );
    }

    iRenderer* RendererTask::getRenderer() const {
        return pRenderer_.get();
    }

}