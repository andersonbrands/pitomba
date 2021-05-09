
#include "D3DRenderer.h"


namespace pitomba {

    bool D3DRenderer::initialize() {
        pWin_ = std::make_unique<D3DWindow>(windowTitle_);
        return pWin_->initialize();
    }

    void D3DRenderer::start() {
        pWin_->start();
    }

    void D3DRenderer::fillSurface(float, float, float) {}

    void D3DRenderer::fillSurface(ColorRGB) {}

    void D3DRenderer::update() {
        pWin_->update();
    }

}