
#ifndef TEXTURE_MANAGER_H_
#define TEXTURE_MANAGER_H_

#include "../../Utils/UnorderedMapContainer.h"
#include "../../Utils/Singleton.h"
#include "../../Utils/Utils.h"
#include "../../Utils/ServiceLocator.h"
#include <string>
#include <d3dx9.h>
#include "../../EventManager/iEventManager.h"
#include "../../EventManager/EventData.h"
#include "../../EventManager/EventId.h"
#include "../../Renderer/iRenderer.h"


using namespace std;

namespace pitomba {

    class TextureManager : public UnorderedMapContainer<unsigned int, LPDIRECT3DTEXTURE9>, public Singleton<TextureManager> {
    private:
        const wstring TEXTURE_DIR;
        iEventManager* pEventManager_ = ServiceLocator::getEventManager();
        iRenderer* pRenderer_ = ServiceLocator::getRenderer();

    public:
        explicit TextureManager(const wstring& textureDir) : UnorderedMapContainer(), TEXTURE_DIR(textureDir) {};
        ~TextureManager() final = default;

        LPDIRECT3DTEXTURE9* loadTexture(const IdAndName& idAndName);
        void unloadTexture(const IdAndName& idAndName);

    };

    inline LPDIRECT3DTEXTURE9* TextureManager::loadTexture(const IdAndName& idAndName) {
        LPDIRECT3DTEXTURE9* result = add(idAndName.id);

        pRenderer_->createD3DTexture(
            (TEXTURE_DIR + idAndName.name),
            idAndName.id
        );

        return result;
    }

    inline void TextureManager::unloadTexture(const IdAndName& idAndName) {
        remove(idAndName.id);
    }

}

#endif // TEXTURE_MANAGER_H_
