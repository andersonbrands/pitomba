
#ifndef D3D_SPRITE_H_
#define D3D_SPRITE_H_

#include "Sprite.h"
#include "../../Math/Vector3.h"
#include <d3dx9.h>
#include "../../EventManager/iEventManager.h"
#include "../../Utils/ServiceLocator.h"

namespace pitomba {


    class D3DSprite : public Sprite {
    private:

        iEventManager* pEventManager_ = ServiceLocator::getEventManager();
        iRenderer* pRenderer_ = ServiceLocator::getRenderer();

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
        D3DSprite() = default;
        ~D3DSprite() final;

        void render();
    };
}

#endif // D3D_SPRITE_H_
