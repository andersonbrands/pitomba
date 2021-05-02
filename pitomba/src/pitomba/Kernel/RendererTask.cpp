#include "RendererTask.h"
#include "../Utils/Logger.h"
#include "../Utils/Utils.h"
#include "../Renderer/SDLRenderer.h"
#include "TimerTask.h"


namespace pitomba {

    RendererTask::RendererTask(const unsigned int priority)
        : Task(priority), pRenderer_(new SDLRenderer("Pitomba Sample!")) {}

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
        std::function<void()> random_fill = [&]() {
            pRenderer_->fillSurface(rand_color_RGB());
        };
        scheduler_.setInterval(1000, random_fill);
    }

    void RendererTask::onUpdate() {
        scheduler_.tick(TimerTask::getInstancePtr()->getDelta());
        pRenderer_->update();
    }

    void RendererTask::onStop() {
        Logger::getInstancePtr()->debug(
            "RendererTask stop!"
        );
    }

}