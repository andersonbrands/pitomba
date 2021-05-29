
#ifndef I_TEXTURE_DIR_PROVIDER_H_
#define I_TEXTURE_DIR_PROVIDER_H_

#include <string>


using namespace std;

namespace pitomba {

    class iTextureDirProvider {

    public:
        virtual ~iTextureDirProvider() = default;

        virtual wstring getTextureDir() = 0;
    };
}

#endif // I_TEXTURE_DIR_PROVIDER_H_
