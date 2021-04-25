#ifndef RENDERER_H_
#define RENDERER_H_

#include "Task.h"
#include "../Utils/Singleton.h"

namespace pitomba {

    class RendererTask : public Task, public Singleton<RendererTask> {
    private:

    public:
        explicit RendererTask(const unsigned int priority);
        virtual ~RendererTask();

        // task interface
        void onStart() final;
        void onStop() final;
    };
}

#endif // RENDERER_H_
