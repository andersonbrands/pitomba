
#ifndef D3D_MOUSE_H_
#define D3D_MOUSE_H_

#include "iMouse.h"
#include <dinput.h>


namespace pitomba {

    class D3DMouse : public iMouse {
    public:

        D3DMouse() = default;
        ~D3DMouse() final;

        void initialize(LPDIRECTINPUT8 mpDI, HWND hWnd);
        void update();

        // Inherited via iMouse
        bool isMouseLeftButtonDown() override;
        bool onMouseLeftButtonDown() override;
        bool onMouseLeftButtonUp() override;
        float getDeltaX() const override;
        float getDeltaY() const override;


    private:
        LPDIRECTINPUTDEVICE8 pDIMouseDevice_; //mouse interface
        float mouseDeltaX_ = 0.0F;
        float mouseDeltaY_ = 0.0F;
        float mouseSensibility_ = 0.005F;
        bool mouseLeftButtonIsDown_ = false;
        bool lastMouseLeftButtonIsDown_ = false;
    };

}

#endif // D3D_MOUSE_H_
