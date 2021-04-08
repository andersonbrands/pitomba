#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "..\Utils\Logger.h"


namespace pitomba {

    class Application {

    private:

    protected:
        Logger logger_;

    public:
        explicit Application() {}
        virtual ~Application() {}

        virtual bool initialize() = 0;
        virtual void run() {
            logger_.debug("Application running");
        }
    };

}

#endif // APPLICATION_H_