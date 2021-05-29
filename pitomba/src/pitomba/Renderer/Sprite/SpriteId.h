#ifndef SPRITE_ID_H_
#define SPRITE_ID_H_

#include "../../Math/Vector3.h"
#include "SpriteAlign.h"


namespace pitomba {

    using SpriteId = unsigned int;

    using SpriteInfo = struct {
        SpriteId id;
        Vector3 uuWidth;
        Vector3 vvHeight;
        unsigned int textureId;
        SpriteAlign align;
    };

}
#endif // SPRITE_ID_H_
