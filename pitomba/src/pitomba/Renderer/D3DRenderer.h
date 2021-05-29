
#ifndef D3D_RENDERER_H_
#define D3D_RENDERER_H_

#include "iRenderer.h"
#include "iWindowProvider.h"
#include <d3dx9.h>
#include <string>


namespace pitomba {

    class D3DRenderer : public iRenderer {

    public:
        // delete copy constructor
        D3DRenderer(const D3DRenderer&) = delete;
        // delete copy assignment
        D3DRenderer& operator=(const D3DRenderer&) = delete;

        explicit D3DRenderer(iWindowProvider* windowProvider);
        ~D3DRenderer() final;

        HRESULT setupD3D();
        bool isDeviceLost();

        // Inherited via iRenderer
        bool initialize() override;
        void start() override;
        void fillSurface(ColorRGB) override;
        bool preRender() override;
        void render() override;
        void postRender() override;
        void createD3DTexture(std::wstring const& fullPath, LPDIRECT3DTEXTURE9* texture) override;
        void createD3DVertexBuffer(int bufferSize, DWORD fvf, LPDIRECT3DVERTEXBUFFER9* vertexBuffer) override;
        void renderTexture(LPDIRECT3DTEXTURE9 texture, LPDIRECT3DVERTEXBUFFER9 vertexBuffer, std::size_t vertexStructSize, DWORD fvf) override;
        void setupViewMatrix(float aspectRatio, const Vector3& camPos, const Vector3& camTarget, const Vector3& upVector) override;
        void setTransform(const Vector3& pos, const Vector3& scale, const Vector3& rotation) override;
        void setupLHOrthogonalProjectionMatrix(float w, float h, float zNear, float zFar) override;

    private:
        LPDIRECT3D9 g_pD3D = nullptr;
        LPDIRECT3DDEVICE9 g_pd3dDevice = nullptr;

        D3DPRESENT_PARAMETERS d3dParams_ = {}; //everything we need to setup D3D

        ColorRGB clearColor = { 0.2F,0.2F,0.2F };

        iWindowProvider* pWindowProvider_;
    };

}

#endif // D3D_RENDERER_H_
