#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "..\Utils\Logger.h"
#include "..\Kernel\Kernel.h"


namespace pitomba {

    class Application {

    private:

    protected:
        Logger logger_;
        Kernel kernel_;

    public:
        explicit Application() {}
        virtual ~Application() {}

        virtual bool initialize() = 0;
        virtual void run() {
            logger_.debug("Application running");
            kernel_.execute();
        }
    };

}

#endif // APPLICATION_H_