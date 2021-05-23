
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
        Vector3(0.1875F, 0.8125F, 155.0F),
        Vector3(0.3046F, 0.6953F, 85.0F),
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
            auto setupViewMatrixData = ev::data::SetupViewMatrix{
                aspectRatio,
                camPos,
                camTarget,
                upVector
            };

            pEventManager_->sendEvent(ev::id::SETUP_VIEW_MATRIX, &setupViewMatrixData);

            float zNear = -1.0F;
            float zFar = 4.0F;

            auto setupLHOrthogonalProjectionMatrixData = ev::data::setupLHOrthogonalProjectionMatrix{
                w,
                h,
                zNear,
                zFar
            };

            pEventManager_->sendEvent(ev::id::SETUP_LH_ORTHOGONAL_PROJECTION_MATRIX, &setupLHOrthogonalProjectionMatrixData);
            break;
        }
        case ev::id::RENDER:
            sprite.render();
            break;
        default:
            break;
    }
}
