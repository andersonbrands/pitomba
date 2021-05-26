
#ifndef LOGGER_H_
#define LOGGER_H_


#include "iLogger.h"


namespace pitomba {

    class Logger : public iLogger {

    private:
        void print(const std::string& message) const;

    public:
        Logger() = default;
        ~Logger() final = default;


        // Inherited via iLogger
        void debug(const std::string& message) const override;
        void debug(const boost::format& message) const override;

    };

}


#endif // LOGGER_H_