
#ifndef EVENT_DATA_H_
#define EVENT_DATA_H_

#include <string>
#include <d3dx9.h>
#include "../Math/Vector3.h"
#include "../Renderer/iRenderer.h"
#include "../Input/iKeyboard.h"
#include "../Input/iMouse.h"


namespace pitomba {

    namespace ev {

        namespace data {

            struct Render {
                iRenderer* pRenderer;
            };

            struct InputUpdated {
                iKeyboard* pKeyboard;
                iMouse* pMouse;
            };

        }
    }
}

#endif // EVENT_DATA_H_
