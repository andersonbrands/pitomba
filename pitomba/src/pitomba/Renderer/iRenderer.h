
#ifndef I_RENDERER_H_
#define I_RENDERER_H_

#include "../Utils/Color.h"


namespace pitomba {

    class iRenderer {
    public:
        explicit iRenderer() = default;
        virtual ~iRenderer() = default;

        virtual bool initialize() = 0;
        virtual void fillSurface(int, int, int) = 0;
        virtual void fillSurface(ColorRGB) = 0;
        virtual void update() = 0;

    };
}

#endif // I_RENDERER_H_
