
#include "TextureManager.h"


namespace pitomba {

    LPDIRECT3DTEXTURE9* TextureManager::loadTexture(const IdAndName& idAndName) {
        return add(idAndName.id);
    }

    void TextureManager::unloadTexture(const IdAndName& idAndName) {
        remove(idAndName.id);
    }

    LPDIRECT3DTEXTURE9* TextureManager::getTexture(unsigned int textureId) {
        return get(textureId);
    }

    wstring TextureManager::getTextureDir() {
        return TEXTURE_DIR;
    }

}