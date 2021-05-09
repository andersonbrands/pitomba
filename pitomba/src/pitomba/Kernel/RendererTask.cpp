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
            // event pre render

            pRenderer_->render();
            // event render
            scheduler_.tick(TimerTask::getInstancePtr()->getDelta());

            pRenderer_->postRender();
            // event post render
        }

    }

    void RendererTask::onStop() {
        Logger::getInstancePtr()->debug(
            "RendererTask stop!"
        );
    }

}