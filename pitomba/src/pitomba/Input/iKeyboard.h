
#ifndef I_KEYBOARD_H_
#define I_KEYBOARD_H_


namespace pitomba {

    class iKeyboard {
    public:
        iKeyboard() = default;
        virtual ~iKeyboard() = default;

        virtual bool isKeyDown(unsigned char charCode) = 0;
        virtual bool onKeyDown(unsigned char charCode) = 0;
        virtual bool onKeyUp(unsigned char charCode) = 0;
    };

}

#endif // I_KEYBOARD_H_
