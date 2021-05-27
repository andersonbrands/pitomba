
#ifndef TEXTURE_MANAGER_H_
#define TEXTURE_MANAGER_H_

#include "iTextureManager.h"
#include "../../Utils/UnorderedMapContainer.h"
#include "../../Utils/ServiceLocator.h"
#include <string>


using namespace std;

namespace pitomba {

    class TextureManager : public UnorderedMapContainer<unsigned int, LPDIRECT3DTEXTURE9>, public iTextureManager {
    private:
        const wstring TEXTURE_DIR;
        iEventManager* pEventManager_ = ServiceLocator::getEventManager();

    public:
        explicit TextureManager(const wstring& textureDir) : UnorderedMapContainer(), TEXTURE_DIR(textureDir) {};
        ~TextureManager() final = default;

        // Inherited via iTextureManager
        LPDIRECT3DTEXTURE9* loadTexture(const IdAndName& idAndName) override;
        void unloadTexture(const IdAndName& idAndName) override;
        LPDIRECT3DTEXTURE9* getTexture(unsigned int textureId) override;
        wstring getTextureDir() override;

    };

}

#endif // TEXTURE_MANAGER_H_
