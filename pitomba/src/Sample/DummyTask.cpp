
#include "DummyTask.h"
#include "../pitomba/Renderer/Texture/TextureManager.h"
#include "../pitomba/EventManager/EventId.h"
#include "../pitomba/EventManager/EventData.h"
#include "Ids/TextureIds.h"


DummyTask::DummyTask(const unsigned int priority) : Task(priority) {

}

void DummyTask::onUpdate() {
    if (!isRunning()) return;
}

void DummyTask::onStart() {
    TextureManager::getInstancePtr()->loadTexture(texture::SAMPLE_TEXTURE);

    sprite.setup(
        Vector3(0.0F, 0.0937525F, 24.0F),
        Vector3(0.0F, 0.09375F, 24.0F),
        texture::SAMPLE_TEXTURE.id,
        pitomba::Sprite::SpriteAlign::CENTER
    );

    pEventManager_->attachEvent(ev::id::RENDER, *this);
    pEventManager_->attachEvent(ev::id::PRE_RENDER, *this);
}

void DummyTask::handleEvent(EventId eventId, void* pData) {
    switch (eventId) {
        case ev::id::PRE_RENDER:
        {
            Vector3 camPos(0.0f);
            Vector3 camTarget(0.0f, 0.0f, 1.0f);
            Vector3 upVector(0.0f, 1.0f, 0.0f);

            float w = 160.0F;
            float h = 90.0F;
            auto aspectRatio = w / h;
            float zNear = -10.0F;
            float zFar = 10.0F;

            pRenderer_->setupViewMatrix(aspectRatio, camPos, camTarget, upVector);
            pRenderer_->setupLHOrthogonalProjectionMatrix(w, h, zNear, zFar);
            break;
        }
        case ev::id::RENDER:
        {
            auto pos = Vector3(
                pRng_->rand_float(-40.0F, 40.0F),
                pRng_->rand_float(-40.0F, 40.0F),
                0.0F
            );
            auto scale = Vector3(1.0F);
            auto rotation = Vector3(0.0F);
            pRenderer_->setTransform(pos, scale, rotation);
            sprite.render();

            break;
        }
        default:
            break;
    }
}
