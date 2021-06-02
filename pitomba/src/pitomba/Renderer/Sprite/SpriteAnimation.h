
#ifndef SPRITE_ANIMATION_H_
#define SPRITE_ANIMATION_H_

#include "D3DSprite.h"
#include <vector>
#include "../../Math/Vector3.h"
#include "../../Utils/Utils.h"

using namespace std;

namespace pitomba {

    class SpriteAnimation {
    private:
        // frame starts count at 1, zero means no frame is to be displayed
        unsigned int currentFrame_ = 0;
        float fps_ = 24.0F;
        float spf_ = 1 / fps_;
        bool loop_ = true;
        bool playing_ = false;
        float deltaTime_ = 0.0F;

        vector<D3DSprite*> spriteV_;
    public:
        SpriteAnimation() = default;
        SpriteAnimation(unsigned int totalFrames, float fps);
        SpriteAnimation(unsigned int totalFrames, float fps, bool loop);
        virtual ~SpriteAnimation();

        void addFrame(D3DSprite* pSprite);

        unsigned int getCurrentFrame() const {
            return currentFrame_;
        }

        void goToAndPlay(unsigned int frame);
        void goToAndPause(unsigned int frame);
        void play();
        void stop();
        void pause();

        void update(TimeUnit delta);

        void render();
    };

}

#endif // SPRITE_ANIMATION_H_
