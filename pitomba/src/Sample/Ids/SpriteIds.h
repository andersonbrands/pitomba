
#ifndef SPRITE_IDS_H_
#define SPRITE_IDS_H_

#include "../../pitomba/Renderer/Sprite/Sprite.h"
#include "../../pitomba/Renderer/Sprite/SpriteId.h"
#include "TextureIds.h"


using namespace pitomba;


namespace spr {
    /*
    static const SpriteInfo SPRITE_NAME = {
        id,
        uuWidth,
        vvHeight,
        textureId,
        align
    }
    */
    static const SpriteInfo STAR = {
        0,
        Vector3(0.0F, 0.0937525F, 24.0F),
        Vector3(0.0F, 0.09375F, 24.0F),
        texture::SAMPLE_TEXTURE.id,
        SpriteAlign::CENTER
    };

}

#endif // SPRITE_IDS_H_
