
#ifndef LOGGER_H_
#define LOGGER_H_

#include "Singleton.h"
#include <string>
#include <boost/format.hpp>


namespace pitomba {

    class Logger : public Singleton<Logger> {

    private:
        void print(const std::string& message);

    protected:

    public:
        Logger();
        virtual ~Logger();

        void debug(const std::string& message);
        void debug(const boost::format& message);
    };

}


#endif // LOGGER_H_