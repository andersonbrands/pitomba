
#include "DummyTask.h"
#include "Ids/TextureIds.h"


DummyTask::DummyTask(const unsigned int priority,
                     iLocator<iEventManager>* pEventManagerLocator,
                     iLocator<iRenderer>* pRendererLocator,
                     iLocator<iRng>* pRngLocator,
                     iLocator<iTextureManager>* pTextureManagerLocator) :
    Task(priority),
    pEventManagerLocator_(pEventManagerLocator),
    pRendererLocator_(pRendererLocator),
    pRngLocator_(pRngLocator),
    pTextureManagerLocator_(pTextureManagerLocator),
    sprite(pRendererLocator, pTextureManagerLocator_) {

}

void DummyTask::onUpdate() {
    if (!isRunning()) return;
}

void DummyTask::onStart() {
    pTextureManagerLocator_->get()->loadTexture(texture::SAMPLE_TEXTURE);
    pRendererLocator_->get()->createD3DTexture(
        (pTextureManagerLocator_->get()->getTextureDir() + texture::SAMPLE_TEXTURE.name),
        pTextureManagerLocator_->get()->getTexture(texture::SAMPLE_TEXTURE.id)
    );

    sprite.setup(
        Vector3(0.0F, 0.0937525F, 24.0F),
        Vector3(0.0F, 0.09375F, 24.0F),
        texture::SAMPLE_TEXTURE.id,
        pitomba::Sprite::SpriteAlign::CENTER
    );

    pEventManagerLocator_->get()->attachEvent(ev::id::RENDER, *this);
    pEventManagerLocator_->get()->attachEvent(ev::id::PRE_RENDER, *this);
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

            pRendererLocator_->get()->setupViewMatrix(aspectRatio, camPos, camTarget, upVector);
            pRendererLocator_->get()->setupLHOrthogonalProjectionMatrix(w, h, zNear, zFar);
            break;
        }
        case ev::id::RENDER:
        {
            auto pos = Vector3(
                pRngLocator_->get()->rand_float(-40.0F, 40.0F),
                pRngLocator_->get()->rand_float(-40.0F, 40.0F),
                0.0F
            );
            auto scale = Vector3(1.0F);
            auto rotation = Vector3(0.0F);
            pRendererLocator_->get()->setTransform(pos, scale, rotation);
            sprite.render();

            break;
        }
        default:
            break;
    }
}
