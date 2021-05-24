
#ifndef I_RENDERER_H_
#define I_RENDERER_H_

#include "../Utils/Color.h"
#include "../Math/Vector3.h"
#include <d3dx9.h>
#include <string>


namespace pitomba {

    class iRenderer {
    public:
        explicit iRenderer() = default;
        virtual ~iRenderer() = default;

        virtual bool initialize() = 0;
        virtual void start() = 0;
        virtual void fillSurface(ColorRGB) = 0;
        virtual bool preRender() = 0;
        virtual void render() = 0;
        virtual void postRender() = 0;
        virtual void createD3DTexture(std::wstring fullPath, unsigned int textureId) = 0;
        virtual void createD3DVertexBuffer(int bufferSize, DWORD fvf, LPDIRECT3DVERTEXBUFFER9* vertexBuffer) = 0;
        virtual void renderTexture(LPDIRECT3DTEXTURE9 texture, LPDIRECT3DVERTEXBUFFER9 vertexBuffer, std::size_t vertexStructSize, DWORD fvf) = 0;
        virtual void setupViewMatrix(float aspectRatio, const Vector3& camPos, const Vector3& camTarget, const Vector3& upVector) = 0;
        virtual void setTransform(const Vector3& pos, const Vector3& scale, const Vector3& rotation) = 0;
        virtual void setupLHOrthogonalProjectionMatrix(float w, float h, float zNear, float zFar) = 0;
    };
}

#endif // I_RENDERER_H_
