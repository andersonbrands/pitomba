
#ifndef SPRITE_IDS_H_
#define SPRITE_IDS_H_

#include "../../pitomba/Renderer/Sprite/Sprite.h"
#include "../../pitomba/Renderer/Sprite/SpriteId.h"
#include "TextureIds.h"


using namespace pitomba;


namespace spr {

    namespace _ {
        static const float STAR_W = 0.0937525F;
    }
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
        Vector3(_::STAR_W * 0, _::STAR_W * 1, 24.0F),
        Vector3(0.0F, 0.09375F, 24.0F),
        texture::SAMPLE_TEXTURE.id,
        SpriteAlign::CENTER
    };
    static const SpriteInfo STAR_01 = {
        1,
        Vector3(_::STAR_W * 1, _::STAR_W * 2, 24.0F),
        Vector3(0.0F, 0.09375F, 24.0F),
        texture::SAMPLE_TEXTURE.id,
        SpriteAlign::CENTER
    };
    static const SpriteInfo STAR_02 = {
        2,
        Vector3(_::STAR_W * 2, _::STAR_W * 3, 24.0F),
        Vector3(0.0F, 0.09375F, 24.0F),
        texture::SAMPLE_TEXTURE.id,
        SpriteAlign::CENTER
    };
    static const SpriteInfo STAR_03 = {
        3,
        Vector3(_::STAR_W * 3, _::STAR_W * 4, 24.0F),
        Vector3(0.0F, 0.09375F, 24.0F),
        texture::SAMPLE_TEXTURE.id,
        SpriteAlign::CENTER
    };
    static const SpriteInfo STAR_04 = {
        4,
        Vector3(_::STAR_W * 4, _::STAR_W * 5, 24.0F),
        Vector3(0.0F, 0.09375F, 24.0F),
        texture::SAMPLE_TEXTURE.id,
        SpriteAlign::CENTER
    };
    static const SpriteInfo STAR_05 = {
        5,
        Vector3(_::STAR_W * 5, _::STAR_W * 6, 24.0F),
        Vector3(0.0F, 0.09375F, 24.0F),
        texture::SAMPLE_TEXTURE.id,
        SpriteAlign::CENTER
    };

    static const SpriteInfo MOUSE_POINTER = {
        6,
        Vector3(0.0F, 15.0F / 1024.0F, 15.0F / 8.0F),
        Vector3(1000.0F / 1024.0F, 1.0F, 24.0F / 8.0F),
        texture::SAMPLE_TEXTURE.id,
        SpriteAlign::TOP_LEFT
    };

}

#endif // SPRITE_IDS_H_
