#include "Utils.h"

#include <chrono>
#include <thread>
#include "Rng.h"

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
        const float MILLI_TO_SECONDS_MULTIPLIER = 0.001F;
        return time * MILLI_TO_SECONDS_MULTIPLIER;
    }

    int rand_int(int min, int max) {
        return Rng::getInstancePtr()->rand_int(min, max);
    }

    float rand_float(float min, float max) {
        return Rng::getInstancePtr()->rand_float(min, max);
    }

    ColorRGB rand_color_RGB() {
        auto color = ColorRGB{
            rand_int(0, 255),
            rand_int(0, 255),
            rand_int(0, 255)
        };
        return color;
    }

    ColorRGBA rand_color_RGBA() {
        auto color = ColorRGBA{
            rand_int(0, 255),
            rand_int(0, 255),
            rand_int(0, 255),
            rand_int(0, 255)
        };
        return color;
    }

}