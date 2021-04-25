#ifndef RENDERER_H_
#define RENDERER_H_

#include "Task.h"
#include "../Utils/Singleton.h"
#include "../Renderer/SDLRenderer.h"

namespace pitomba {

    class RendererTask : public Task, public Singleton<RendererTask> {

    public:
        explicit RendererTask(const unsigned int priority);
        ~RendererTask() final = default;

        void onStart() final;
        void onUpdate() final;
        void onStop() final;

    private:
        SDLRenderer renderer = SDLRenderer("Pitomba Sample!");
    };

}

#endif // RENDERER_H_
