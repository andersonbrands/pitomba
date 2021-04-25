
#include "Logger.h"
#include <iostream>


namespace pitomba {

    void Logger::print(const std::string& message) const {
        std::cout << message << "\n";
    }

    void Logger::debug(const std::string& message) const {
        print(message);
    }

    void Logger::debug(const boost::format& message) const {
        print(boost::str(message));
    }

}