
#include "Logger.h"
#include <iostream>


namespace pitomba {

    Logger::Logger() {

    }

    Logger::~Logger() {

    }

    void Logger::print(const std::string& message) {
        std::cout << message << "\n";
    }

    void Logger::debug(const std::string& message) {
        print(message);
    }

    void Logger::debug(const boost::format& message) {
        print(boost::str(message));
    }

}