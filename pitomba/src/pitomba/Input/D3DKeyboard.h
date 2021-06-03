
#ifndef D3D_KEYBOARD_H_
#define D3D_KEYBOARD_H_

#include "iKeyboard.h"
#include <dinput.h>


namespace pitomba {

    class D3DKeyboard : public iKeyboard {
    private:
        static const int BUFFER_SIZE = 256;			//keyboards are fixed size
        LPDIRECTINPUTDEVICE8 pDIKeyboardDevice_;	//keyboard interface

        char buffer_[BUFFER_SIZE];
        char lastBuffer_[BUFFER_SIZE];				//remember what was down previously for press+release

    public:
        D3DKeyboard() = default;
        ~D3DKeyboard() final;

        void initialize(LPDIRECTINPUT8 mpDI, HWND hWnd);

        void update();


        // Inherited via iKeyboard
        bool isKeyDown(unsigned char charCode) override;
        bool onKeyDown(unsigned char charCode) override;
        bool onKeyUp(unsigned char charCode) override;

    };
}

#endif // D3D_KEYBOARD_H_
