
#ifndef LOGGER_H_
#define LOGGER_H_

#include "Singleton.h"
#include <string>
#include <boost/format.hpp>


namespace pitomba {

    class Logger : public Singleton<Logger> {

    private:
        void print(const std::string& message) const;

    public:
        Logger() = default;
        virtual ~Logger() = default;

        void debug(const std::string& message) const;
        void debug(const boost::format& message) const;
    };

}


#endif // LOGGER_H_