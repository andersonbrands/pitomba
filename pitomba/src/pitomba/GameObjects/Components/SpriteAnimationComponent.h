
#ifndef SPRITE_ANIMATION_COMPONENT_H_
#define SPRITE_ANIMATION_COMPONENT_H_

#include "../Component.h"
#include "../ComponentId.h"
#include "../../Renderer/Sprite/SpriteAnimation.h"
#include "../../EventManager/EventHandler.h"
#include "../../EventManager/Event.h"

namespace pitomba {

    class SpriteAnimationComponent : public Component, public EventHandler {
    public:
        using Component::Component;
        ~SpriteAnimationComponent() final = default;

        static ComponentId getId() {
            return component::SPRITE_ANIMATION;
        }


        // Inherited via EventHandler
        void handleEvent(EventId eventId, void* pData) override;

        SpriteAnimation* getAnimation() const {
            return pAnimation_;
        }

        void setAnimation(SpriteAnimation* animation) {
            pAnimation_ = animation;
        }

    private:
        SpriteAnimation* pAnimation_;
    };

}

#endif // SPRITE_ANIMATION_COMPONENT_H_
