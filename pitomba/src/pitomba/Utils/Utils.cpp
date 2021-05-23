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
        const float MILLI_TO_SECONDS_MULTIPLIER = 0.001F;
        return time * MILLI_TO_SECONDS_MULTIPLIER;
    }

    ColorRGB rand_color_RGB(iRng& rng) {
        auto color = ColorRGB{
            rng.rand_float(0.0F, 1.0F),
            rng.rand_float(0.0F, 1.0F),
            rng.rand_float(0.0F, 1.0F)
        };
        return color;
    }

    ColorRGBA rand_color_RGBA(iRng& rng) {
        auto color = ColorRGBA{
            rng.rand_float(0.0F, 1.0F),
            rng.rand_float(0.0F, 1.0F),
            rng.rand_float(0.0F, 1.0F),
            rng.rand_float(0.0F, 1.0F)
        };
        return color;
    }

}