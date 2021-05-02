#ifndef RENDERER_H_
#define RENDERER_H_

#include "Task.h"
#include "../Utils/Singleton.h"
#include "../Renderer/iRenderer.h"
#include "../Utils/Scheduler.h"

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
    };

}

#endif // RENDERER_H_
