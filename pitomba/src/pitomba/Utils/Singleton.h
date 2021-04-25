
#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <cassert>

namespace pitomba {

    template <typename T>
    class Singleton {
    private:
        static T* instance;

    public:
        Singleton() {
            assert(!instance);
            instance = static_cast<T*>(this);
        }

        ~Singleton() {
            assert(instance);
            instance = nullptr;
        }

        static T& getInstance() {
            return *instance;
        }
        static T* getInstancePtr() {
            return instance;
        }
    };

    template <typename T> T* Singleton<T>::instance = 0;
}

#endif // SINGLETON_H_
