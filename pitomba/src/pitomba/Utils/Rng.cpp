
#include "Rng.h"

namespace pitomba {
    int Rng::rand_int(int min, int max) {
        std::uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }

    float Rng::rand_float(float min, float max) {
        const float from_zero_to_one = (float)rand_int(0, 10000) / 10000.0F;
        return min + (max - min) * from_zero_to_one;
    }
}
