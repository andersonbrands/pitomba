#ifndef I_RNG_H_
#define I_RNG_H_


namespace pitomba {

    class iRng {

    public:
        virtual ~iRng() = default;

        virtual int rand_int(int, int) = 0;
        virtual float rand_float(float, float) = 0;
    };
}
#endif // I_RNG_H_
