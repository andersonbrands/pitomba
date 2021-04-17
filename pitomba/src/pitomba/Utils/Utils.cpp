#include "Utils.h"

#include <chrono>
#include <thread>

using namespace std::chrono;


namespace pitomba {

    void sleep(long ms) {
        std::this_thread::sleep_for(milliseconds(ms));
    }

    TimeUnit now() {
        auto epoch = system_clock::now().time_since_epoch();
        return duration_cast<milliseconds>(epoch).count();
    }

    float toSeconds(TimeUnit time) {
        const float MILLI_TO_SECONDS_MULTIPLIER = 0.001f;
        return time * MILLI_TO_SECONDS_MULTIPLIER;
    }

}