
#ifndef D3D_WINDOW_H_
#define D3D_WINDOW_H_

#include "BaseWindow.h"
#include "iRenderer.h"
#include "../EventManager/EventManager.h"
#include "../Math/Vector3.h"
#include <string>
#include <d3dx9.h>


namespace pitomba {
    class D3DWindow : public BaseWindow<D3DWindow>, public iRenderer {
    public:
        explicit D3DWindow(std::wstring const& windowTitle) : windowTitle_(windowTitle) {};
        virtual ~D3DWindow();
        PCWSTR  ClassName() const final { return L"D3D Window Class"; }
        PCWSTR  WindowTitle() const final { return windowTitle_.c_str(); }
        LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) final;

        // iRenderer interface
        bool initialize() final;
        void start() final;
        void fillSurface(ColorRGB) final;
        bool preRender() final;
        void render() final;
        void postRender() final;

    private:
        std::wstring windowTitle_;

        LPDIRECT3D9 g_pD3D;
        LPDIRECT3DDEVICE9 g_pd3dDevice;

        D3DPRESENT_PARAMETERS d3dParams_; //everything we need to setup D3D

        ColorRGB clearColor = { 0.2F,0.2F,0.2F };
        HRESULT setupD3D();
        bool isDeviceLost();

        void renderTexture(LPDIRECT3DTEXTURE9 texture, LPDIRECT3DVERTEXBUFFER9 vertexBuffer, std::size_t vertexStructSize, DWORD fvf);
        void setupViewMatrix(float aspectRatio, const Vector3& camPos, const Vector3& camTarget, const Vector3& upVector = Vector3(0.0f, 0.1f, 0.0f));
        void setTransform(const Vector3& pos, const Vector3& scale, const Vector3& rotation);
        void setupLHOrthogonalProjectionMatrix(float w, float h, float zNear, float zFar);
    };
}

#endif // D3D_WINDOW_H_
