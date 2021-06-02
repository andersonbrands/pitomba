
#ifndef I_RENDERABLE_TEXTURE_H_
#define I_RENDERABLE_TEXTURE_H_

#include <d3dx9.h>
#include <cstddef>

namespace pitomba {

    class iRenderableTexture {

    public:
        virtual ~iRenderableTexture() = default;

        virtual LPDIRECT3DTEXTURE9 getTexture() = 0;
        virtual LPDIRECT3DVERTEXBUFFER9 getVertexBuffer() = 0;
        virtual std::size_t getVertexStructSize() = 0;
        virtual DWORD getFVF() = 0;
    };
}

#endif // I_RENDERABLE_TEXTURE_H_
