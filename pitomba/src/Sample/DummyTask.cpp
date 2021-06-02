
#include "DummyTask.h"
#include "Ids/TextureIds.h"
#include "Ids/SpriteIds.h"
#include "../pitomba/GameObjects/Components/SpriteComponent.h"
#include "../pitomba/GameObjects/Components/TransformComponent.h"


DummyTask::DummyTask(const unsigned int priority,
                     iLocator<iEventManager>* pEventManagerLocator,
                     iLocator<iRenderer>* pRendererLocator,
                     iLocator<iRng>* pRngLocator,
                     iLocator<iTimer>* pTimerLocator,
                     iLocator<iTextureContainer>* pTextureContainerLocator,
                     iTextureDirProvider* pTextureDirProvider) :
    Task(priority),
    pEventManagerLocator_(pEventManagerLocator),
    pRendererLocator_(pRendererLocator),
    pRngLocator_(pRngLocator),
    pTimerLocator_(pTimerLocator),
    pTextureContainerLocator_(pTextureContainerLocator),
    pTextureDirProvider_(pTextureDirProvider),
    sprite(pRendererLocator_, pTextureContainerLocator_),
    starSprite_0(pRendererLocator_, pTextureContainerLocator_),
    starSprite_1(pRendererLocator_, pTextureContainerLocator_),
    starSprite_2(pRendererLocator_, pTextureContainerLocator_),
    starSprite_3(pRendererLocator_, pTextureContainerLocator_),
    starSprite_4(pRendererLocator_, pTextureContainerLocator_),
    starSprite_5(pRendererLocator_, pTextureContainerLocator_) {

}

void DummyTask::onUpdate() {
    if (!isRunning()) return;

    auto pos = Vector3(
        pRngLocator_->get()->rand_float(20.0F, 40.0F),
        pRngLocator_->get()->rand_float(20.0F, 40.0F),
        0.0F
    );

    star_.get<TransformComponent>()->setTranslation(pos);

    starAnimation_.update(pTimerLocator_->get()->delta());
}

void DummyTask::onStart() {
    pTextureContainerLocator_->get()->add(texture::SAMPLE_TEXTURE.id);
    pRendererLocator_->get()->createD3DTexture(
        (pTextureDirProvider_->getTextureDir() + texture::SAMPLE_TEXTURE.name),
        pTextureContainerLocator_->get()->get(texture::SAMPLE_TEXTURE.id)
    );

    sprite.setup(spr::STAR);

    star_.setActive(true);
    star_.add<SpriteComponent>();
    star_.add<TransformComponent>();

    star_.get<SpriteComponent>()->setSprite(&sprite);

    starSprite_0.setup(spr::STAR);
    starSprite_1.setup(spr::STAR_01);
    starSprite_2.setup(spr::STAR_02);
    starSprite_3.setup(spr::STAR_03);
    starSprite_4.setup(spr::STAR_04);
    starSprite_5.setup(spr::STAR_05);

    starAnimation_.addFrame(&starSprite_0);
    starAnimation_.addFrame(&starSprite_1);
    starAnimation_.addFrame(&starSprite_2);
    starAnimation_.addFrame(&starSprite_3);
    starAnimation_.addFrame(&starSprite_4);
    starAnimation_.addFrame(&starSprite_5);
    starAnimation_.addFrame(&starSprite_4);
    starAnimation_.addFrame(&starSprite_3);
    starAnimation_.addFrame(&starSprite_2);
    starAnimation_.addFrame(&starSprite_1);

    starAnimation_.play();

    pEventManagerLocator_->get()->attachEvent(ev::id::PRE_RENDER, *this);
    pEventManagerLocator_->get()->attachEvent(ev::id::RENDER, *this);
    pEventManagerLocator_->get()->attachEvent(ev::id::RENDER, *star_.get<SpriteComponent>());
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
            pRendererLocator_->get()->setTransform(Vector3(0.0F), Vector3(1.0F), Vector3(0.0F));
            starAnimation_.render();

            pRendererLocator_->get()->setTransform(star_.get<TransformComponent>()->getMatrix());
            break;
        }
        default:
            break;
    }
}
