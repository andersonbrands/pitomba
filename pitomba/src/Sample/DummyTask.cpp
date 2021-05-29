
#include "DummyTask.h"
#include "Ids/TextureIds.h"
#include "Ids/SpriteIds.h"


DummyTask::DummyTask(const unsigned int priority,
                     iLocator<iEventManager>* pEventManagerLocator,
                     iLocator<iRenderer>* pRendererLocator,
                     iLocator<iRng>* pRngLocator,
                     iLocator<iTextureContainer>* pTextureContainerLocator,
                     iTextureDirProvider* pTextureDirProvider) :
    Task(priority),
    pEventManagerLocator_(pEventManagerLocator),
    pRendererLocator_(pRendererLocator),
    pRngLocator_(pRngLocator),
    pTextureContainerLocator_(pTextureContainerLocator),
    pTextureDirProvider_(pTextureDirProvider),
    sprite(pRendererLocator, pTextureContainerLocator_) {

}

void DummyTask::onUpdate() {
    if (!isRunning()) return;
}

void DummyTask::onStart() {
    pTextureContainerLocator_->get()->add(texture::SAMPLE_TEXTURE.id);
    pRendererLocator_->get()->createD3DTexture(
        (pTextureDirProvider_->getTextureDir() + texture::SAMPLE_TEXTURE.name),
        pTextureContainerLocator_->get()->get(texture::SAMPLE_TEXTURE.id)
    );

    sprite.setup(spr::STAR);

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
