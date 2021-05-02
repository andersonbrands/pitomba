#ifndef RENDERER_H_
#define RENDERER_H_

#include "Task.h"
#include "../Utils/Singleton.h"
#include "../Renderer/SDLRenderer.h"
#include "../Utils/Scheduler.h"

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
        SDLRenderer renderer_ = SDLRenderer("Pitomba Sample!");
    };

}

#endif // RENDERER_H_
