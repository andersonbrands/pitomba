
#ifndef EVENT_DATA_H_
#define EVENT_DATA_H_

#include <string>
#include <d3dx9.h>
#include "../Math/Vector3.h"
#include "../Renderer/iRenderer.h"


namespace pitomba {

    namespace ev {

        namespace data {

            struct Render {
                iRenderer* PRenderer;
            };

        }
    }
}

#endif // EVENT_DATA_H_
