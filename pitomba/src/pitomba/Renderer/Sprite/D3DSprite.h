
#ifndef D3D_SPRITE_H_
#define D3D_SPRITE_H_

#include "Sprite.h"
#include <d3dx9.h>
#include "../../EventManager/iEventManager.h"
#include "../../Renderer/iRenderer.h"
#include "../../Renderer/Texture/iTextureContainer.h"
#include "../../Renderer/Texture/iRenderableTexture.h"
#include "../../Utils/iLocator.h"


namespace pitomba {


    class D3DSprite : public Sprite, public iRenderableTexture {
    private:
        iLocator<iTextureContainer>* pTextureContainerLocator_;
        iLocator<iRenderer>* pRendererLocator_;

        struct SPRITE_VERTEX {
            D3DXVECTOR3 position;
            //D3DXVECTOR3 normal;
            FLOAT u;
            FLOAT v;
        };
        static const DWORD FVF_SPRITE_VERTEX = (D3DFVF_XYZ /*| D3DFVF_NORMAL*/ | D3DFVF_TEX1);;

        SPRITE_VERTEX* vertices_ = new SPRITE_VERTEX[4];

        LPDIRECT3DVERTEXBUFFER9 pVertexBuffer_ = nullptr;

        void createVertexBuffer();

        void applySettings() final;
        void setUVCoords(float minU, float maxU, float minV, float maxV) final;

    public:
        explicit D3DSprite(iLocator<iRenderer>* pRendererLocator, iLocator<iTextureContainer>* pTextureContainerLocator);
        ~D3DSprite() final;

        // Inherited via iRenderableTexture
        LPDIRECT3DTEXTURE9 getTexture() override;
        LPDIRECT3DVERTEXBUFFER9 getVertexBuffer() override;
        std::size_t getVertexStructSize() override;
        DWORD getFVF() override;
    };
}

#endif // D3D_SPRITE_H_
