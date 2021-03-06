
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
        void render(iRenderableTexture* renderableTexture) override;
        void postRender() override;
        void createD3DTexture(std::wstring const& fullPath, LPDIRECT3DTEXTURE9* texture) override;
        void createD3DVertexBuffer(int bufferSize, DWORD fvf, LPDIRECT3DVERTEXBUFFER9* vertexBuffer) override;
        void renderTexture(LPDIRECT3DTEXTURE9 texture, LPDIRECT3DVERTEXBUFFER9 vertexBuffer, std::size_t vertexStructSize, DWORD fvf) override;
        void setupViewMatrix(float aspectRatio, const Vector3& camPos, const Vector3& camTarget, const Vector3& upVector) override;
        void setTransform(const Matrix4& matrix) override;
        void setTransform(const Transform& transform) override;
        void setTransform(const Vector3& pos, const Vector3& scale, const Vector3& rotation) override;
        void setupLHOrthogonalProjectionMatrix(float w, float h, float zNear, float zFar) override;
        RECT drawText(std::wstring const& text, int xPosition, int yPosition, ColorRGBA color, LPD3DXSPRITE sprite = nullptr,
                      int textBoxWidth = 0, int textBoxHeight = 0, FontAlign alignment = FontAlign::LEFT, bool dimensionsOnly = false) const;
        void drawLine(const Vector3& from, const Vector3& to, const ColorRGBA& color = ColorRGBA{ 1.0f, 1.0f, 1.0f, 1.0f }) const override;
        void drawAABB(const Vector3& min, const Vector3& max, const ColorRGBA& color = ColorRGBA{ 1.0f, 1.0f, 1.0f, 1.0f }) override;

        bool createFont(std::wstring const& faceName, int size, bool bold = FALSE, bool italic = FALSE);
    private:
        LPDIRECT3D9 g_pD3D = nullptr;
        LPDIRECT3DDEVICE9 g_pd3dDevice = nullptr;

        D3DPRESENT_PARAMETERS d3dParams_ = {}; //everything we need to setup D3D

        ColorRGB clearColor = { 0.2F,0.2F,0.2F };

        iWindowProvider* pWindowProvider_;

        LPD3DXFONT pFont_ = nullptr;

        using VertexDiffuse = struct {
            float x;
            float y;
            float z;
            D3DCOLOR diffuse;
        };

    };

}

#endif // D3D_RENDERER_H_
