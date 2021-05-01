#ifndef RNG_H_
#define RNG_H_

#include <random>
#include "Singleton.h"


namespace pitomba {

    class Rng : public Singleton<Rng> {

    public:
        Rng() = default;
        virtual ~Rng() = default;

        int rand_int(int, int);
        float rand_float(float, float);
    private:
        std::random_device rd;
        std::mt19937 gen = std::mt19937(rd());

    };
}
#endif // RNG_H_
