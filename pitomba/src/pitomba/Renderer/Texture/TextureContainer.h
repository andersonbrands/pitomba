
#ifndef TEXTURE_CONTAINER_H_
#define TEXTURE_CONTAINER_H_

#include "iTextureDirProvider.h"
#include "../../Utils/UnorderedMapContainer.h"
#include <d3dx9.h>

using namespace std;

namespace pitomba {

    class TextureContainer : public UnorderedMapContainer<unsigned int, LPDIRECT3DTEXTURE9>, public iTextureDirProvider {
    private:
        const wstring TEXTURE_DIR;

    public:
        explicit TextureContainer(const wstring& textureDir) : UnorderedMapContainer(), TEXTURE_DIR(textureDir) {};
        ~TextureContainer() final = default;

        // Inherited via iTextureDirProvider
        wstring getTextureDir() override;

    };

}

#endif // TEXTURE_CONTAINER_H_
