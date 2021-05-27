
#ifndef I_TEXTURE_MANAGER_H_
#define I_TEXTURE_MANAGER_H_

#include "../../Utils/Utils.h"
#include <d3dx9.h>
#include <string>


using namespace std;

namespace pitomba {

    class iTextureManager {

    public:
        virtual ~iTextureManager() = default;

        virtual LPDIRECT3DTEXTURE9* loadTexture(const IdAndName& idAndName) = 0;
        virtual void unloadTexture(const IdAndName& idAndName) = 0;
        virtual LPDIRECT3DTEXTURE9* getTexture(unsigned int textureId) = 0;
        virtual wstring getTextureDir(void) = 0;
    };
}

#endif // I_TEXTURE_MANAGER_H_
