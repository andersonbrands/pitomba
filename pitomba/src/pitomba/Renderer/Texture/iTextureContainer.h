
#ifndef I_TEXTURE_CONTAINER_H_
#define I_TEXTURE_CONTAINER_H_


#include "../../Utils/iContainer.h"
#include <d3dx9.h>


namespace pitomba {

    using iTextureContainer = iContainer<unsigned int, LPDIRECT3DTEXTURE9>;

}

#endif // I_TEXTURE_CONTAINER_H_
