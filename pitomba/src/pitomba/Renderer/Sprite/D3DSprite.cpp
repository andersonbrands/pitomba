
#include "D3DSprite.h"

#include <cassert>


namespace pitomba {
    D3DSprite::D3DSprite(
        iLocator<iRenderer>* pRendererLocator,
        iLocator<iTextureContainer>* pTextureContainerLocator) :
        pTextureContainerLocator_(pTextureContainerLocator),
        pRendererLocator_(pRendererLocator) {}

    D3DSprite::~D3DSprite() {
        if (vertices_) {
            delete[] vertices_;
            vertices_ = nullptr;

            if (pVertexBuffer_) {
                pVertexBuffer_->Release();
                pVertexBuffer_ = nullptr;
            }
        }
    }

    LPDIRECT3DTEXTURE9 D3DSprite::getTexture() {
        return *pTextureContainerLocator_->get()->get(getTextureId());
    }

    LPDIRECT3DVERTEXBUFFER9 D3DSprite::getVertexBuffer() {
        return pVertexBuffer_;
    }

    std::size_t D3DSprite::getVertexStructSize() {
        return sizeof(SPRITE_VERTEX);
    }

    DWORD D3DSprite::getFVF() {
        return FVF_SPRITE_VERTEX;
    }

    void D3DSprite::createVertexBuffer() {
        const int numVertices(6);
        const int bufferSize(numVertices * sizeof(SPRITE_VERTEX));

        pRendererLocator_->get()->createD3DVertexBuffer(
            bufferSize,
            FVF_SPRITE_VERTEX,
            &pVertexBuffer_
        );

        SPRITE_VERTEX* pVertices(nullptr);

        auto lockResult = pVertexBuffer_->Lock(0, 0, (void**)&pVertices, 0);
        assert(!FAILED(lockResult));

        pVertices[0] = vertices_[3];
        pVertices[1] = vertices_[0];
        pVertices[2] = vertices_[1];

        pVertices[3] = vertices_[3];
        pVertices[4] = vertices_[1];
        pVertices[5] = vertices_[2];

        pVertexBuffer_->Unlock();
    }

    void D3DSprite::applySettings() {
        // top left
        vertices_[0].position = D3DXVECTOR3(0.0f, getHeight(), 0.0f);
        // top right
        vertices_[1].position = D3DXVECTOR3(getWidth(), getHeight(), 0.0f);
        // bottom right
        vertices_[2].position = D3DXVECTOR3(getWidth(), 0.0f, 0.0f);
        // bottom left
        vertices_[3].position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);


        /*
        // use normal?
        D3DXVECTOR3 normal(0, 0, -1);

        vertices_[0].normal = normal;
        vertices_[1].normal = normal;
        vertices_[2].normal = normal;
        vertices_[3].normal = normal;
        */

        D3DXVECTOR3 offset(0, 0, 0);

        switch (getAlign()) {
            case SpriteAlign::BOTTOM_LEFT:
                // no offset needed
                break;
            case SpriteAlign::TOP_LEFT:
                offset = vertices_[0].position;
                break;
            case SpriteAlign::TOP_RIGHT:
                offset = vertices_[1].position;
                break;
            case SpriteAlign::BOTTOM_RIGHT:
                offset = vertices_[2].position;
                break;
            case SpriteAlign::CENTER:
                offset = D3DXVECTOR3(getWidth() / 2.0f, getHeight() / 2.0f, 0);
                break;
            case SpriteAlign::CENTER_LEFT:
                offset = D3DXVECTOR3(0, getHeight() / 2.0f, 0);
                break;
            case SpriteAlign::CENTER_TOP:
                offset = D3DXVECTOR3(getWidth() / 2.0f, getHeight(), 0);
                break;
            case SpriteAlign::CENTER_RIGHT:
                offset = D3DXVECTOR3(getWidth(), getHeight() / 2.0f, 0);
                break;
            case SpriteAlign::CENTER_BOTTOM:
                offset = D3DXVECTOR3(getWidth() / 2.0f, 0, 0);
                break;
            default:
                return;
        }

        vertices_[0].position -= offset;
        vertices_[1].position -= offset;
        vertices_[2].position -= offset;
        vertices_[3].position -= offset;

        createVertexBuffer();
    }

    void D3DSprite::setUVCoords(float minU, float maxU, float minV, float maxV) {
        vertices_[0].u = minU;
        vertices_[0].v = minV;

        vertices_[1].u = maxU;
        vertices_[1].v = minV;

        vertices_[2].u = maxU;
        vertices_[2].v = maxV;

        vertices_[3].u = minU;
        vertices_[3].v = maxV;
    }

}