
#ifndef D3D_RENDERER_H_
#define D3D_RENDERER_H_

#include "D3DWindow.h"
#include <memory>
#include <string>


namespace pitomba {

    class D3DRenderer : public D3DWindow {

    public:
        // delete copy constructor
        D3DRenderer(const D3DRenderer&) = delete;
        // delete copy assignment
        D3DRenderer& operator=(const D3DRenderer&) = delete;

        using D3DWindow::D3DWindow;
        ~D3DRenderer() final = default;

    };
}

#endif // D3D_RENDERER_H_
