#ifndef DUMMY_TASK_H_
#define DUMMY_TASK_H_


#include <memory>
#include "../pitomba/Kernel/Task.h"
#include "../pitomba/Renderer/Sprite/D3DSprite.h"
#include "../pitomba/Renderer/Sprite/SpriteAnimation.h"
#include "../pitomba/Utils/iLocator.h"
#include "../pitomba/Utils/iRng.h"
#include "../pitomba/Utils/iTimer.h"
#include "../pitomba/EventManager/EventHandler.h"
#include "../pitomba/Utils/iContainer.h"
#include "../pitomba/Renderer/Texture/iTextureDirProvider.h"
#include "../pitomba/Renderer/Texture/iTextureContainer.h"
#include "../pitomba/GameObjects/GameObject.h"


using namespace pitomba;

class DummyTask : public Task, public EventHandler {
public:
    explicit DummyTask(
        const unsigned int priority,
        iLocator<iEventManager>* pEventManagerLocator,
        iLocator<iRenderer>* pRendererLocator,
        iLocator<iRng>* pRngLocator,
        iLocator<iTimer>* pTimerLocator,
        iLocator<iTextureContainer>* pTextureContainerLocator,
        iTextureDirProvider* pTextureDirProvider);
    ~DummyTask() final = default;

private:

    iLocator<iEventManager>* pEventManagerLocator_;
    iLocator<iRenderer>* pRendererLocator_;
    iLocator<iRng>* pRngLocator_;
    iLocator<iTimer>* pTimerLocator_;
    iLocator<iTextureContainer>* pTextureContainerLocator_;
    iTextureDirProvider* pTextureDirProvider_;

    void onUpdate() final;
    void onStart() final;

    D3DSprite sprite;
    GameObject star_;
    GameObject animatedStar_;

    D3DSprite starSprite_0;
    D3DSprite starSprite_1;
    D3DSprite starSprite_2;
    D3DSprite starSprite_3;
    D3DSprite starSprite_4;
    D3DSprite starSprite_5;
    SpriteAnimation starAnimation_ = SpriteAnimation(10, 2);


    // EventHandler interface
    void handleEvent(EventId eventId, void* pData) override;
};

#endif // DUMMY_TASK_H_ 
