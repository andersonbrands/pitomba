#ifndef RNG_H_
#define RNG_H_

#include <random>
#include "iRng.h"

namespace pitomba {

    class Rng : public iRng {

    public:
        Rng() = default;
        ~Rng() final = default;

        int rand_int(int, int) final;
        float rand_float(float, float) final;
    private:
        std::random_device rd;
        std::mt19937 gen = std::mt19937(rd());

    };
}
#endif // RNG_H_
