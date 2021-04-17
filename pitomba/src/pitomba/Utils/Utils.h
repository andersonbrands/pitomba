
#ifndef PITOMBA_UTILS_H_
#define PITOMBA_UTILS_H_


namespace pitomba {

    typedef long long TimeUnit;

    void sleep(long);
    TimeUnit now();

    float toSeconds(TimeUnit);
}

#endif // PITOMBA_UTILS_H_
