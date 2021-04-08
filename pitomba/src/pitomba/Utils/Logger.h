
#ifndef LOGGER_H_
#define LOGGER_H_

#include "Singleton.h"
#include <string>


namespace pitomba {

    class Logger : public Singleton<Logger> {

    private:
        void print(const std::string& message);

    protected:

    public:
        Logger();
        virtual ~Logger();

        void debug(const std::string& message);
    };

}


#endif // LOGGER_H_