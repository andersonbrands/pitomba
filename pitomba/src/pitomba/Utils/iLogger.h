
#ifndef I_LOGGER_H_
#define I_LOGGER_H_

#include <string>
#include <boost/format.hpp>


namespace pitomba {

    class iLogger {
    public:
        virtual ~iLogger() = default;

        virtual void debug(const std::string& message) const = 0;
        virtual void debug(const boost::format& message) const = 0;
    };

}


#endif // I_LOGGER_H_