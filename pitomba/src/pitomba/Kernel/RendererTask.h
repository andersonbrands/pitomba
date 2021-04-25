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
        virtual void start();
        virtual void pause();
        virtual void update();
        virtual void resume();
        virtual void stop();
    };
}

#endif // RENDERER_H_
