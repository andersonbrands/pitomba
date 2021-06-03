
#ifndef I_MOUSE_H_
#define I_MOUSE_H_


namespace pitomba {

    class iMouse {
    public:
        iMouse() = default;
        virtual ~iMouse() = default;

        virtual bool isMouseLeftButtonDown() = 0;
        virtual bool onMouseLeftButtonDown() = 0;
        virtual bool onMouseLeftButtonUp() = 0;

        virtual float getDeltaX() const = 0;
        virtual float getDeltaY() const = 0;
    };

}

#endif // I_MOUSE_H_
