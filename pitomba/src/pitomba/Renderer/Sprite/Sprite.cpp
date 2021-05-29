
#include "Sprite.h"


namespace pitomba {

    void Sprite::setup(const Vector3& uuWidth, const Vector3& vvHeight, unsigned int textureId, SpriteAlign align) {
        setUVCoords(uuWidth.getX(), uuWidth.getY(), vvHeight.getX(), vvHeight.getY());

        align_ = align;
        height_ = vvHeight.getZ();
        width_ = uuWidth.getZ();

        textureId_ = textureId;

        applySettings();
    }

    void Sprite::setup(const SpriteInfo& spriteInfo) {
        setup(
            spriteInfo.uuWidth,
            spriteInfo.vvHeight,
            spriteInfo.textureId,
            spriteInfo.align
        );
    }

}