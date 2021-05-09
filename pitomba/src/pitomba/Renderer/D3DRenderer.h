
#ifndef D3D_RENDERER_H_
#define D3D_RENDERER_H_

#include "iRenderer.h"
#include "D3DWindow.h"
#include <memory>
#include <string>


namespace pitomba {

    class D3DRenderer : public iRenderer {

    public:
        // delete copy constructor
        D3DRenderer(const D3DRenderer&) = delete;
        // delete copy assignment
        D3DRenderer& operator=(const D3DRenderer&) = delete;

        explicit D3DRenderer(const std::wstring& windowTitle) : windowTitle_(windowTitle) {};
        ~D3DRenderer() final = default;

        // iRenderer interface
        bool initialize() final;
        void start() final;
        void fillSurface(float, float, float) final;
        void fillSurface(ColorRGB) final;
        void update() final;

    private:
        std::unique_ptr<D3DWindow> pWin_;
        std::wstring windowTitle_;
    };
}

#endif // D3D_RENDERER_H_
