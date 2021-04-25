#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../Utils/Logger.h"
#include "../Kernel/Kernel.h"


namespace pitomba {

    class Application {

    private:
        Kernel kernel_;

    public:
        explicit Application() = default;
        virtual ~Application() = default;

        virtual bool initialize() = 0;
        virtual void run() {
            Logger::getInstancePtr()->debug("Application running");
            kernel_.execute();
        }

        void addTask(Task* pTask) {
            kernel_.addTask(pTask);
        };
    };

}

#endif // APPLICATION_H_