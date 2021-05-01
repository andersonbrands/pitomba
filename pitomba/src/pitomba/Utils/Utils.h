
#ifndef PITOMBA_UTILS_H_
#define PITOMBA_UTILS_H_


namespace pitomba {

    using TimeUnit = long long;

    void sleep(long);
    TimeUnit now();

    float toSeconds(TimeUnit);

    int rand_int(int, int);
    float rand_float(float, float);
}

#endif // PITOMBA_UTILS_H_
