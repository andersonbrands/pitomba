
#ifndef SPRITE_COMPONENT_H_
#define SPRITE_COMPONENT_H_

#include "../Component.h"
#include "../ComponentId.h"
#include "../../Renderer/Sprite/D3DSprite.h"
#include "../../EventManager/EventHandler.h"
#include "../../EventManager/Event.h"


namespace pitomba {

    class SpriteComponent : public Component, public EventHandler {
    private:
        D3DSprite* pSprite_ = nullptr;
    public:
        using Component::Component;
        ~SpriteComponent() final = default;

        static ComponentId getId() {
            return component::SPRITE;
        }

        void setSprite(D3DSprite* pSprite) {
            pSprite_ = pSprite;
        }


        // Inherited via EventHandler
        void handleEvent(EventId eventId, void* pData) override;

    };

}

#endif // SPRITE_COMPONENT_H_
