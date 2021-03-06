
#include "D3DRenderer.h"
#include <cassert>
#include <d3dx9core.h>

namespace pitomba {

    D3DRenderer::D3DRenderer(iWindowProvider* windowProvider) : pWindowProvider_(windowProvider) {

    }
    D3DRenderer::~D3DRenderer() {
        if (g_pd3dDevice) g_pd3dDevice->Release();
        if (g_pD3D) g_pD3D->Release();

        if (pFont_) {
            pFont_->Release();
            pFont_ = nullptr;
        }
    }

    bool D3DRenderer::initialize() {
        if (!SUCCEEDED(setupD3D())) {
            return false;
        }

        createFont(L"Arial", 20);

        return true;
    }

    void D3DRenderer::start() {
        g_pd3dDevice->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);
    }

    void D3DRenderer::fillSurface(ColorRGB color) {
        clearColor = color;
    }

    bool D3DRenderer::preRender() {
        isDeviceLost();

        auto d3dColor = D3DCOLOR_XRGB((int)(clearColor.r * 255), (int)(clearColor.g * 255), (int)(clearColor.b * 255));
        g_pd3dDevice->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, d3dColor, 1.0f, 0);

        return SUCCEEDED(g_pd3dDevice->BeginScene());
    }

    void D3DRenderer::render() {
        // nothing to do here
    }

    void D3DRenderer::postRender() {
        g_pd3dDevice->EndScene();

        // Present the backbuffer to the display.
        g_pd3dDevice->Present(nullptr, nullptr, nullptr, nullptr);
    }

    HRESULT D3DRenderer::setupD3D() {
        // Create the D3D object, return failure if this can't be done.
        if (!(g_pD3D = Direct3DCreate9(D3D_SDK_VERSION))) return E_FAIL;

        // Set up the structure used to create the D3DDevice
        ZeroMemory(&d3dParams_, sizeof(d3dParams_));
        d3dParams_.BackBufferWidth = 0;
        d3dParams_.BackBufferHeight = 0;
        d3dParams_.BackBufferFormat = D3DFMT_UNKNOWN;
        d3dParams_.BackBufferCount = 1;
        d3dParams_.MultiSampleType = D3DMULTISAMPLE_NONE;
        d3dParams_.MultiSampleQuality = 0;
        d3dParams_.SwapEffect = D3DSWAPEFFECT_DISCARD;
        d3dParams_.hDeviceWindow = pWindowProvider_->getWindow();
        d3dParams_.Windowed = true;
        d3dParams_.EnableAutoDepthStencil = true;
        d3dParams_.AutoDepthStencilFormat = D3DFMT_D24S8;
        d3dParams_.Flags = 0;
        d3dParams_.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
        d3dParams_.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

        // Create the D3DDevice
        if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, pWindowProvider_->getWindow(),
                                        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                        &d3dParams_, &g_pd3dDevice))) {
            return E_FAIL;
        }

        // Turn on the Z buffer
        g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

        return S_OK;
    }

    bool D3DRenderer::isDeviceLost() {
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

    void D3DRenderer::createD3DTexture(std::wstring const& fullPath, LPDIRECT3DTEXTURE9* texture) {
        auto createTextureResult = D3DXCreateTextureFromFile(
            g_pd3dDevice,
            fullPath.c_str(),
            texture
        );
        assert(!FAILED(createTextureResult));
    }

    void D3DRenderer::createD3DVertexBuffer(int bufferSize, DWORD fvf, LPDIRECT3DVERTEXBUFFER9* vertexBuffer) {
        auto createVertexBufferResult = g_pd3dDevice->CreateVertexBuffer(bufferSize, 0, fvf, D3DPOOL_DEFAULT, vertexBuffer, nullptr);
        assert(!FAILED(createVertexBufferResult));
    }

    void D3DRenderer::renderTexture(LPDIRECT3DTEXTURE9 texture, LPDIRECT3DVERTEXBUFFER9 vertexBuffer, std::size_t vertexStructSize, DWORD fvf) {
        g_pd3dDevice->SetTexture(0, texture);

        g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
        g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
        g_pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
        g_pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);

        g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);

        g_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
        g_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

        g_pd3dDevice->SetStreamSource(0, vertexBuffer, 0, vertexStructSize);
        g_pd3dDevice->SetFVF(fvf);
        g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

        g_pd3dDevice->SetTexture(0, nullptr);
    }

    void D3DRenderer::setupViewMatrix(float aspectRatio, const Vector3& camPos, const Vector3& camTarget, const Vector3& upVector /*= Vector3(0.0f, 0.1f, 0.0f) */) {
        // Set up the view matrix.
        // This defines which way the 'camera' will look at, and which way is up.
        D3DXVECTOR3 vCamera(camPos.getX(), camPos.getY(), camPos.getZ());
        D3DXVECTOR3 vLookat(camTarget.getX(), camTarget.getY(), camTarget.getZ());
        D3DXVECTOR3 vUpVector(upVector.getX(), upVector.getY(), upVector.getZ());
        D3DXMATRIX matView;
        D3DXMatrixLookAtLH(&matView, &vCamera, &vLookat, &vUpVector);
        g_pd3dDevice->SetTransform(D3DTS_VIEW, &matView);

        // Set up the projection matrix.
        // This transforms 2D geometry into a 3D space.
        D3DXMATRIX matProj;
        D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, aspectRatio, 1.0f, 400.0f);
        g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);
    }

    void D3DRenderer::setTransform(const Vector3& pos, const Vector3& scale, const Vector3& rotation) {
        // Set up matrices to control transformations and transform
        D3DXMATRIX WorldMat;
        D3DXMATRIX TranslateMat;
        D3DXMATRIX ScaleMat;
        D3DXMATRIX RotateMat;
        D3DXMatrixTranslation(&TranslateMat, pos.getX(), pos.getY(), pos.getZ());
        D3DXMatrixScaling(&ScaleMat, scale.getX(), scale.getY(), scale.getZ());
        D3DXMatrixIdentity(&WorldMat);
        if (rotation.getX() != 0) {
            D3DXMatrixRotationX(&RotateMat, rotation.getX());
            D3DXMatrixMultiply(&WorldMat, &WorldMat, &RotateMat);
        }
        if (rotation.getY() != 0) {
            D3DXMatrixRotationY(&RotateMat, rotation.getY());
            D3DXMatrixMultiply(&WorldMat, &WorldMat, &RotateMat);
        }
        if (rotation.getZ() != 0) {
            D3DXMatrixRotationZ(&RotateMat, rotation.getZ());
            D3DXMatrixMultiply(&WorldMat, &WorldMat, &RotateMat);
        }
        D3DXMatrixMultiply(&WorldMat, &WorldMat, &ScaleMat);
        D3DXMatrixMultiply(&WorldMat, &WorldMat, &TranslateMat);

        g_pd3dDevice->SetTransform(D3DTS_WORLD, &WorldMat);
    }

    void D3DRenderer::setupLHOrthogonalProjectionMatrix(float w, float h, float zNear, float zFar) {
        D3DXMATRIX matProj;
        D3DXMatrixOrthoLH(&matProj, w, h, zNear, zFar);
        g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);
    }

    bool D3DRenderer::createFont(std::wstring const& faceName, int size, bool bold, bool italic) {
        HRESULT hr = 0;

        hr = D3DXCreateFont(g_pd3dDevice, -size, 0, bold ? 800 : 0, 1, italic, DEFAULT_CHARSET,
                            OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, faceName.c_str(), &pFont_);
        if (FAILED(hr)) {
            MessageBox(nullptr, L"D3DXCreateFont() failed.", L"Error", MB_OK);
            return false;
        }

        return true;
    }

    void D3DRenderer::drawLine(const Vector3& from, const Vector3& to, const ColorRGBA& color) const {

        const DWORD vertex_difuse(D3DFVF_XYZ | D3DFVF_DIFFUSE);

        VertexDiffuse line_vertices[2];

        int r(int(color.r * 255));
        int g(int(color.g * 255));
        int b(int(color.b * 255));

        line_vertices[0].x = from.getX();
        line_vertices[0].y = from.getY();
        line_vertices[0].z = from.getZ();
        line_vertices[0].diffuse = D3DCOLOR_XRGB(r, g, b);

        line_vertices[1].x = to.getX();
        line_vertices[1].y = to.getY();
        line_vertices[1].z = to.getZ();
        line_vertices[1].diffuse = D3DCOLOR_XRGB(r, g, b);

        DWORD renderState = g_pd3dDevice->GetRenderState(D3DRS_LIGHTING, &renderState);

        g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

        g_pd3dDevice->SetFVF(vertex_difuse);
        g_pd3dDevice->DrawPrimitiveUP(D3DPT_LINELIST, 2, line_vertices, sizeof(VertexDiffuse));

        g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, renderState);

    }

    void D3DRenderer::drawAABB(const Vector3& min, const Vector3& max, const ColorRGBA& color) {
        setTransform(Vector3(0.0F), Vector3(1.0F), Vector3(0.0F));

        Vector3 start, end;

        start = Vector3(min.getX(), max.getY(), min.getZ());
        end = Vector3(min.getX(), max.getY(), max.getZ());
        drawLine(start, end, color);

        start = end;
        end = Vector3(max.getX(), max.getY(), max.getZ());
        drawLine(start, end, color);
        start = end;
        end = Vector3(max.getX(), max.getY(), min.getZ());
        drawLine(start, end, color);
        start = end;
        end = Vector3(min.getX(), max.getY(), min.getZ());
        drawLine(start, end, color);

        start = Vector3(min.getX(), min.getY(), min.getZ());
        end = Vector3(min.getX(), min.getY(), max.getZ());
        drawLine(start, end, color);
        start = end;
        end = Vector3(max.getX(), min.getY(), max.getZ());
        drawLine(start, end, color);
        start = end;
        end = Vector3(max.getX(), min.getY(), min.getZ());
        drawLine(start, end, color);
        start = end;
        end = Vector3(min.getX(), min.getY(), min.getZ());
        drawLine(start, end, color);

        start = Vector3(min.getX(), min.getY(), min.getZ());
        end = Vector3(min.getX(), max.getY(), min.getZ());
        drawLine(start, end, color);
        start = Vector3(max.getX(), min.getY(), min.getZ());
        end = Vector3(max.getX(), max.getY(), min.getZ());
        drawLine(start, end, color);
        start = Vector3(max.getX(), min.getY(), max.getZ());
        end = Vector3(max.getX(), max.getY(), max.getZ());
        drawLine(start, end, color);
        start = Vector3(min.getX(), min.getY(), max.getZ());
        end = Vector3(min.getX(), max.getY(), max.getZ());
        drawLine(start, end, color);
    }

    RECT D3DRenderer::drawText(std::wstring const& text, int xPosition, int yPosition, ColorRGBA color, LPD3DXSPRITE sprite,
                               int textBoxWidth, int textBoxHeight, FontAlign alignment, bool dimensionsOnly) const {
        RECT rect = { 0,0,0,0 };
        if (!pFont_) {
            return rect;
        }
        DWORD format = DT_EXPANDTABS;
        if (textBoxWidth == 0) {
            format |= DT_NOCLIP;
        } else {
            format |= DT_WORDBREAK;
            switch (alignment) {
                case FontAlign::LEFT:
                    format |= DT_LEFT;
                    break;
                case FontAlign::CENTER:
                    format |= DT_CENTER;
                    break;
                case FontAlign::RIGHT:
                    format |= DT_RIGHT;
                    break;
                case FontAlign::TOP_RIGHT:
                    format |= DT_RIGHT | DT_TOP;
                    break;
                case FontAlign::BOTTOM_RIGHT:
                    format |= DT_RIGHT | DT_BOTTOM;
                    break;
                case FontAlign::TOP_LEFT:
                    format |= DT_LEFT | DT_TOP;
                    break;
                case FontAlign::BOTTOM_LEFT:
                    format |= DT_LEFT | DT_BOTTOM;
                    break;
                default:
                    break;
            }
            if (textBoxHeight == 0) {
                // A width is specified, but not a height.
                // Make it seem like height is infinite
                textBoxHeight = 2000;
            }
        }
        if (dimensionsOnly)
            format |= DT_CALCRECT;

        rect.left = xPosition;
        rect.top = yPosition;
        rect.right = xPosition + textBoxWidth;
        rect.bottom = yPosition + textBoxHeight;

        DWORD d3dColor = D3DCOLOR_RGBA(
            int(255 * color.r),
            int(255 * color.g),
            int(255 * color.b),
            int(255 * color.a)
        );

        pFont_->DrawText(sprite, text.c_str(), -1, &rect, format, d3dColor);

        return rect;
    }

    void D3DRenderer::render(iRenderableTexture* renderableTexture) {
        if (renderableTexture) {
            renderTexture(
                renderableTexture->getTexture(),
                renderableTexture->getVertexBuffer(),
                renderableTexture->getVertexStructSize(),
                renderableTexture->getFVF()
            );
        }
    }

    void D3DRenderer::setTransform(const Matrix4& matrix) {
        D3DMATRIX worldMat;

        worldMat._11 = matrix.get(0);
        worldMat._12 = matrix.get(1);
        worldMat._13 = matrix.get(2);
        worldMat._14 = matrix.get(12);// X
        worldMat._21 = matrix.get(4);
        worldMat._22 = matrix.get(5);
        worldMat._23 = matrix.get(6);
        worldMat._24 = matrix.get(13);// Y
        worldMat._31 = matrix.get(8);
        worldMat._32 = matrix.get(9);
        worldMat._33 = matrix.get(10);
        worldMat._34 = matrix.get(14);// Z
        worldMat._41 = matrix.get(3);// x'
        worldMat._42 = matrix.get(7);// y'
        worldMat._43 = matrix.get(11);// z'
        worldMat._44 = matrix.get(15);

        g_pd3dDevice->SetTransform(D3DTS_WORLD, &worldMat);
    }

    void D3DRenderer::setTransform(const Transform& transform) {
        setTransform(transform.getTranslation(), transform.getScale(), transform.getRotation());
    }

}