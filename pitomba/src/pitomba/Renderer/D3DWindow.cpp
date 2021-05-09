
#include "D3DWindow.h"


namespace pitomba {

    D3DWindow::~D3DWindow() {
        if (g_pd3dDevice) g_pd3dDevice->Release();
        if (g_pD3D) g_pD3D->Release();
    }

    LRESULT D3DWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
        switch (uMsg) {
            case WM_DESTROY:
                EventManager::getInstancePtr()->sendEvent(ev::id::APPLICATION_QUIT);
                PostQuitMessage(0);
                return 0;
            case WM_SHOWWINDOW:
                return 0;
            default:
                return DefWindowProc(Window(), uMsg, wParam, lParam);
        }
        return TRUE;
    }

    bool D3DWindow::initialize() {
        if (!Create(WS_OVERLAPPEDWINDOW)) {
            return false;
        }

        if (!SUCCEEDED(setupD3D())) {
            return false;
        }

        return true;
    }

    void D3DWindow::start() {
        // Show the window
        ShowWindow(Window(), SW_SHOWDEFAULT);
        UpdateWindow(Window());
        g_pd3dDevice->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);
    }

    void D3DWindow::fillSurface(ColorRGB color) {
        clearColor = color;
    }

    bool D3DWindow::preRender() {
        // Run the message loop.
        MSG msg = { };
        ZeroMemory(&msg, sizeof(msg));

        if (PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        isDeviceLost();

        auto d3dColor = D3DCOLOR_XRGB((int)(clearColor.r * 255), (int)(clearColor.g * 255), (int)(clearColor.b * 255));
        g_pd3dDevice->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, d3dColor, 1.0f, 0);

        return SUCCEEDED(g_pd3dDevice->BeginScene());
    }

    void D3DWindow::render() {
        // nothing to do here
    }

    void D3DWindow::postRender() {
        g_pd3dDevice->EndScene();

        // Present the backbuffer to the display.
        g_pd3dDevice->Present(nullptr, nullptr, nullptr, nullptr);
    }

    HRESULT D3DWindow::setupD3D() {
        // Create the D3D object, return failure if this can't be done.
        if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION))) return E_FAIL;


        // Set up the structure used to create the D3DDevice
        ZeroMemory(&d3dParams_, sizeof(d3dParams_));
        d3dParams_.BackBufferWidth = 0;
        d3dParams_.BackBufferHeight = 0;
        d3dParams_.BackBufferFormat = D3DFMT_UNKNOWN;
        d3dParams_.BackBufferCount = 1;
        d3dParams_.MultiSampleType = D3DMULTISAMPLE_NONE;
        d3dParams_.MultiSampleQuality = 0;
        d3dParams_.SwapEffect = D3DSWAPEFFECT_DISCARD;
        d3dParams_.hDeviceWindow = Window();
        d3dParams_.Windowed = true;
        d3dParams_.EnableAutoDepthStencil = true;
        d3dParams_.AutoDepthStencilFormat = D3DFMT_D24S8;
        d3dParams_.Flags = 0;
        d3dParams_.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
        d3dParams_.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

        // Create the D3DDevice
        if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Window(),
                                        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                        &d3dParams_, &g_pd3dDevice))) {
            return E_FAIL;
        }

        // Turn on the Z buffer
        g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

        return S_OK;
    }

    bool D3DWindow::isDeviceLost() {
        assert(g_pd3dDevice);
        // Get the state of the graphics device.
        HRESULT hr = g_pd3dDevice->TestCooperativeLevel();

        // If the device is lost and cannot be reset yet then
        // sleep for a bit and we'll try again on the next
        // message loop cycle.
        if (hr == D3DERR_DEVICELOST) {
            Sleep(20);
            return true;
        }
        // Driver error, exit.
        else if (hr == D3DERR_DRIVERINTERNALERROR) {
            MessageBox(nullptr, L"Internal Driver Error...Exiting", nullptr, 0);
            PostQuitMessage(0);
            return true;
        }
        // The device is lost but we can reset and restore it.
        else if (hr == D3DERR_DEVICENOTRESET) {
            if (!SUCCEEDED(g_pd3dDevice->Reset(&d3dParams_))) {
                MessageBox(nullptr, L"Failed to reset device", L"Error", MB_OK);
            }
            return false;
        } else
            return false;
    }

}
