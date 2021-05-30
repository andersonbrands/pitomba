
#include "SpriteComponent.h"
#include "../GameObject.h"


namespace pitomba {

    void SpriteComponent::handleEvent(EventId eventId, void* pData) {
        if (!getOwner()->isActive()) {
            return;
        }

        if (eventId == ev::id::RENDER) {
            pSprite_->render();
        }
    }

}
