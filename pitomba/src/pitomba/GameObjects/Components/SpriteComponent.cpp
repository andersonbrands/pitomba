
#include "SpriteComponent.h"
#include "../GameObject.h"
#include "TransformComponent.h"
#include "../../EventManager/EventData.h"


namespace pitomba {

    void SpriteComponent::handleEvent(EventId eventId, void* pData) {
        if (!getOwner()->isActive()) {
            return;
        }

        if (eventId == ev::id::RENDER) {
            auto pRenderer(static_cast<ev::data::Render*>(pData)->PRenderer);
            const auto& matrix = getOwner()->get<TransformComponent>()->getMatrix();

            pRenderer->setTransform(matrix);
            pRenderer->render(pSprite_);
        }
    }

}
