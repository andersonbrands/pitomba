
#ifndef PITOMBA_UTILS_H_
#define PITOMBA_UTILS_H_

#include "Color.h"


namespace pitomba {

    using TimeUnit = long long;

    void sleep(long);
    TimeUnit now();

    float toSeconds(TimeUnit);

    int rand_int(int, int);
    float rand_float(float, float);

    ColorRGB rand_color_RGB();
    ColorRGBA rand_color_RGBA();
}

#endif // PITOMBA_UTILS_H_
