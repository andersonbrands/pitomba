
#ifndef D3D_WINDOW_H_
#define D3D_WINDOW_H_

#include "BaseWindow.h"
#include "../EventManager/EventManager.h"
#include <string>
#include <d3dx9.h>


namespace pitomba {
    class D3DWindow : public BaseWindow<D3DWindow> {
    public:
        explicit D3DWindow(std::wstring const& windowTitle) : windowTitle_(windowTitle) {};
        ~D3DWindow() final;
        PCWSTR  ClassName() const final { return L"D3D Window Class"; }
        PCWSTR  WindowTitle() const final { return windowTitle_.c_str(); }
        LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) final;

        bool initialize();
        void start();
        void update();
    private:
        std::wstring windowTitle_;

        LPDIRECT3D9 g_pD3D;
        LPDIRECT3DDEVICE9 g_pd3dDevice;

        D3DPRESENT_PARAMETERS d3dParams_; //everything we need to setup D3D

        HRESULT setupD3D();
        bool isDeviceLost();
    };
}

#endif // D3D_WINDOW_H_
