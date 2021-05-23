
#ifndef PITOMBA_UTILS_H_
#define PITOMBA_UTILS_H_

#include "iRng.h"
#include "Color.h"
#include <string>


namespace pitomba {

    using IdAndName = struct {
        unsigned int id;
        std::wstring name;
    };

    using TimeUnit = long long;

    void sleep(long);
    TimeUnit now();

    float toSeconds(TimeUnit);

    ColorRGB rand_color_RGB(iRng&);
    ColorRGBA rand_color_RGBA(iRng&);
}

#endif // PITOMBA_UTILS_H_
