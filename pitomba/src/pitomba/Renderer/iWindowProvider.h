
#ifndef I_WINDOW_PROVIDER_H_
#define I_WINDOW_PROVIDER_H_

#include <d3dx9.h>


namespace pitomba {

    class iWindowProvider {
    public:
        virtual ~iWindowProvider() = default;

        virtual HWND getWindow() const = 0;
    };
}

#endif // I_WINDOW_PROVIDER_H_
