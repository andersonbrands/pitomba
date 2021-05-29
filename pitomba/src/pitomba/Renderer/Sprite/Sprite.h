
#ifndef SPRITE_H_
#define SPRITE_H_

#include "../../Math/Vector3.h"
#include "SpriteId.h"
#include "SpriteAlign.h"

namespace pitomba {

    class Sprite {
    public:

        Sprite() = default;
        virtual ~Sprite() = default;

        virtual void setUVCoords(float minU, float maxU, float minV, float maxV) = 0;
        virtual void applySettings() = 0;

        void setup(const Vector3& uuWidth, const Vector3& vvHeight, unsigned int textureId, SpriteAlign align);
        void setup(const SpriteInfo& spriteInfo);

    protected:
        float getHeight() const {
            return height_;
        }
        float getWidth() const {
            return width_;
        }
        SpriteAlign getAlign() const {
            return align_;
        }
        unsigned int getTextureId() const {
            return textureId_;
        }

    private:
        SpriteAlign align_;
        float height_;
        float width_;
        unsigned int textureId_;

    };
}

#endif // SPRITE_H_
