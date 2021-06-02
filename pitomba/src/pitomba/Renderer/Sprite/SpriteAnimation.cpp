
#include "SpriteAnimation.h"
#include <cassert>


namespace pitomba {

    SpriteAnimation::SpriteAnimation(unsigned int totalFrames, float fps) : fps_(fps), spf_(1 / fps) {
        spriteV_.reserve(totalFrames);
    }

    SpriteAnimation::SpriteAnimation(unsigned int totalFrames, float fps, bool loop) : fps_(fps), spf_(1 / fps), loop_(loop) {
        spriteV_.reserve(totalFrames);
    }

    SpriteAnimation::~SpriteAnimation() {
        spriteV_.clear();
    }

    void SpriteAnimation::addFrame(iRenderableTexture* pSprite) {
        spriteV_.push_back(pSprite);
    }

    void SpriteAnimation::goToAndPlay(unsigned int frame) {
        assert(frame <= spriteV_.size());
        currentFrame_ = frame;
        play();
    }
    void SpriteAnimation::goToAndPause(unsigned int frame) {
        assert(frame <= spriteV_.size());
        currentFrame_ = frame;
        pause();
    }

    void SpriteAnimation::play() {
        playing_ = true;
        if (currentFrame_ == 0) {
            currentFrame_ = 1;
        }
    }

    void SpriteAnimation::stop() {
        playing_ = false;
        currentFrame_ = 0;
        deltaTime_ = 0.0f;
    }

    void SpriteAnimation::pause() {
        playing_ = false;
    }

    void SpriteAnimation::update(TimeUnit delta) {
        if (!currentFrame_ || !playing_) {
            return;
        }

        deltaTime_ += toSeconds(delta);

        if (deltaTime_ > spf_) {
            ++currentFrame_;
            deltaTime_ -= spf_;
        }

        if (currentFrame_ > spriteV_.size()) {
            if (loop_)
                currentFrame_ = 1;
            else
                stop();
        }

    }

    iRenderableTexture* SpriteAnimation::spriteToRender() {
        if (currentFrame_)
            return spriteV_.at(currentFrame_ - 1);

        return nullptr;
    }

}