
#ifndef SIMPLE_RENDERER_H_
#define SIMPLE_RENDERER_H_

#include "iRenderer.h"
#include <string>
#include "MainWindow.h"
#include "../Utils/Color.h"
#include <memory>

namespace pitomba {

    class SimpleRenderer : public iRenderer {

    public:
        // delete copy constructor
        SimpleRenderer(const SimpleRenderer&) = delete;
        // delete copy assignment
        SimpleRenderer& operator=(const SimpleRenderer&) = delete;

        explicit SimpleRenderer(const std::wstring& windowTitle) : windowTitle_(windowTitle) {};
        ~SimpleRenderer() final = default;

        // iRenderer interface
        bool initialize() final;
        void start() final;
        void fillSurface(float, float, float) final;
        void fillSurface(ColorRGB) final;
        void update() final;
    private:
        std::unique_ptr<MainWindow> pWin_;
        std::wstring windowTitle_;
    };

    bool SimpleRenderer::initialize() {
        pWin_ = std::make_unique<MainWindow>(windowTitle_);

        if (!pWin_->Create(WS_OVERLAPPEDWINDOW)) {
            return false;
        }

        return true;
    }
    inline void SimpleRenderer::start() {
        ShowWindow(pWin_->Window(), SW_SHOWDEFAULT);
    }
    inline void SimpleRenderer::fillSurface(float r, float g, float b) {
        auto brush = CreateSolidBrush(RGB(r * 255, g * 255, b * 255));

        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(pWin_->Window(), &ps);
        FillRect(hdc, &ps.rcPaint, brush);
        EndPaint(pWin_->Window(), &ps);
    }
    inline void SimpleRenderer::fillSurface(ColorRGB colorRGB) {
        fillSurface(colorRGB.r, colorRGB.g, colorRGB.b);
    }
    inline void SimpleRenderer::update() {
        // Run the message loop.
        MSG msg = { };
        ZeroMemory(&msg, sizeof(msg));

        if (PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }


    }
}

#endif // SIMPLE_RENDERER_H_
