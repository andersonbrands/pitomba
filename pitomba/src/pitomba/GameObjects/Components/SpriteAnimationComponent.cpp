
#include "SpriteAnimationComponent.h"
#include "../GameObject.h"
#include "../../EventManager/EventData.h"
#include "TransformComponent.h"


namespace pitomba {

    void SpriteAnimationComponent::handleEvent(EventId eventId, void* pData) {
        if (!getOwner()->isActive()) {
            return;
        }

        if (eventId == ev::id::RENDER) {
            auto pRenderer(static_cast<ev::data::Render*>(pData)->PRenderer);
            const auto& matrix = getOwner()->get<TransformComponent>()->getMatrix();

            pRenderer->setTransform(matrix);
            pRenderer->render(pAnimation_->spriteToRender());
        }
    }

}