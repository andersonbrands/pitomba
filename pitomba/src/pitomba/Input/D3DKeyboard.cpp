
#include "D3DKeyboard.h"


namespace pitomba {

    D3DKeyboard::~D3DKeyboard() {
        if (pDIKeyboardDevice_) {
            // Always unacquire device before calling Release().
            pDIKeyboardDevice_->Unacquire();
            pDIKeyboardDevice_->Release();
            pDIKeyboardDevice_ = nullptr;
        }
    }

    void D3DKeyboard::initialize(LPDIRECTINPUT8 mpDI, HWND hWnd) {

        // Retrieve a pointer to an IDirectInputDevice8 interface.
        if (FAILED(mpDI->CreateDevice(GUID_SysKeyboard, &pDIKeyboardDevice_, nullptr)))
            MessageBox(nullptr, L"DInput CreateDevice failed", L"Error", MB_OK);

        // Set the data format using the predefined keyboard data format.
        if (FAILED(pDIKeyboardDevice_->SetDataFormat(&c_dfDIKeyboard)))
            MessageBox(nullptr, L"Failed to set data format for keyboard", L"Error", MB_OK);

        // Set the cooperative level
        if (FAILED(pDIKeyboardDevice_->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)))
            MessageBox(nullptr, L"Failed to set cooperative level of keyboard", L"Error", MB_OK);

        pDIKeyboardDevice_->Acquire();

        ZeroMemory(&buffer_, BUFFER_SIZE);
        ZeroMemory(&lastBuffer_, BUFFER_SIZE);
    }

    void D3DKeyboard::update() {
        HRESULT hr;

        //remember what was down, so we know when something is pressed and released
        memcpy(lastBuffer_, buffer_, BUFFER_SIZE);

        // Clear the buffer for keyboard data - just in case.
        ZeroMemory(&buffer_, BUFFER_SIZE);

        hr = pDIKeyboardDevice_->GetDeviceState(sizeof(buffer_), (LPVOID)&buffer_);
        if FAILED(hr) {
            // If this failed, the device has probably been lost.
            // Check for (hr == DIERR_INPUTLOST) and attempt to reacquire it here.
            hr = pDIKeyboardDevice_->Acquire();
            while (hr == DIERR_INPUTLOST)
                hr = pDIKeyboardDevice_->Acquire();

            pDIKeyboardDevice_->GetDeviceState(sizeof(buffer_), (LPVOID)&buffer_);
        }
    }


    bool D3DKeyboard::isKeyDown(unsigned char charCode) {
        return (buffer_[charCode] & 0x80) ? true : false;
    }

    bool D3DKeyboard::onKeyDown(unsigned char charCode) {
        return isKeyDown(charCode) && !(lastBuffer_[charCode] & 0x80);
    }

    bool D3DKeyboard::onKeyUp(unsigned char charCode) {
        return !isKeyDown(charCode) && (lastBuffer_[charCode] & 0x80);
    }

}
