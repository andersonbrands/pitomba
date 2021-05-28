
#ifndef I_LOCATOR_H_
#define I_LOCATOR_H_


namespace pitomba {

    template <typename T>
    class iLocator {
    public:

        T* get() {
            return service_;
        }

        void provide(T* service) {
            service_ = service;
        }

    private:

        T* service_;

    };
}

#endif // I_LOCATOR_H_
