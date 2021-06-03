

#include "D3DMouse.h"


namespace pitomba {

    void D3DMouse::initialize(LPDIRECTINPUT8 mpDI, HWND hWnd) {
        if (FAILED(mpDI->CreateDevice(GUID_SysMouse, &pDIMouseDevice_, nullptr)))
            MessageBox(nullptr, L"DInput CreateDevice failed", L"Error", MB_OK);

        if (FAILED(pDIMouseDevice_->SetDataFormat(&c_dfDIMouse2)))
            MessageBox(nullptr, L"Failed to set data for mouse", L"Error", MB_OK);

        if (FAILED(pDIMouseDevice_->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE)))
            MessageBox(nullptr, L"Failed to set cooperative level for mouse", L"Error", MB_OK);

        pDIMouseDevice_->Acquire();
    }

    void D3DMouse::update() {
        HRESULT hr;
        DIMOUSESTATE2 MouseState;      // DirectInput mouse state structure

        // Get the input's device state and store it in 'MouseState'
        ZeroMemory(&MouseState, sizeof(MouseState));
        hr = pDIMouseDevice_->GetDeviceState(sizeof(DIMOUSESTATE2), &MouseState);
        if (FAILED(hr)) {
            hr = pDIMouseDevice_->Acquire();
            while (hr == DIERR_INPUTLOST) hr = pDIMouseDevice_->Acquire();

            pDIMouseDevice_->GetDeviceState(sizeof(DIMOUSESTATE2), &MouseState);
        }

        mouseDeltaX_ = MouseState.lX * mouseSensibility_;
        mouseDeltaY_ = MouseState.lY * mouseSensibility_;

        lastMouseLeftButtonIsDown_ = mouseLeftButtonIsDown_;
        mouseLeftButtonIsDown_ = MouseState.rgbButtons[0] & 0x80;
    }

    D3DMouse::~D3DMouse() {
        if (pDIMouseDevice_) {
            // Always unacquire device before calling Release().
            pDIMouseDevice_->Unacquire();
            pDIMouseDevice_->Release();
            pDIMouseDevice_ = nullptr;
        }
    }

    bool D3DMouse::isMouseLeftButtonDown() {
        return mouseLeftButtonIsDown_;
    }

    bool D3DMouse::onMouseLeftButtonDown() {
        return mouseLeftButtonIsDown_ && !lastMouseLeftButtonIsDown_;
    }

    bool D3DMouse::onMouseLeftButtonUp() {
        return lastMouseLeftButtonIsDown_ && !mouseLeftButtonIsDown_;
    }

    float D3DMouse::getDeltaX() const {
        return mouseDeltaX_;
    }

    float D3DMouse::getDeltaY() const {
        return mouseDeltaY_;
    }

}
