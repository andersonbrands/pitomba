
#ifndef EVENT_DATA_H_
#define EVENT_DATA_H_

#include <string>
#include <d3dx9.h>
#include "../Math/Vector3.h"


namespace pitomba {

    namespace ev {

        namespace data {

            struct CreateD3DTexture {
                std::wstring fullPath;
                unsigned int textureId;
            };

            struct SetupViewMatrix {
                float aspectRatio;
                Vector3 camPos;
                Vector3 camTarget;
                Vector3 upVector;
            };

            struct setupLHOrthogonalProjectionMatrix {
                float w;
                float h;
                float zNear;
                float zFar;
            };

            struct CreateD3DVertexBuffer {
                int bufferSize;
                DWORD fvf;
                LPDIRECT3DVERTEXBUFFER9* vertexBuffer;
            };

            struct RenderTexture {
                unsigned int textureId;
                LPDIRECT3DVERTEXBUFFER9 vertexBuffer;
                std::size_t vertexStructSize;
                DWORD fvf;
            };
        }
    }
}

#endif // EVENT_DATA_H_
