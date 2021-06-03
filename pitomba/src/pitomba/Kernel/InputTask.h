
#ifndef INPUT_TASK_H_
#define INPUT_TASK_H_

#ifndef DIRECTINPUT_VERSION
#define DIRECTINPUT_VERSION 0x0800
#endif


#include "Task.h"
#include "../Input/iKeyboard.h"
#include "../Input/D3DKeyboard.h"
#include "../Input/iMouse.h"
#include "../Input/D3DMouse.h"
#include "../Renderer/iWindowProvider.h"
#include "../EventManager/iEventManager.h"
#include "../Utils/iLocator.h"
#include <memory>


namespace pitomba {

    class InputTask : public Task {
    public:
        explicit InputTask(const unsigned int priority, iLocator<iEventManager>* pEventManagerLocator, iWindowProvider* pWindowProvider) :
            Task(priority), pWindowProvider_(pWindowProvider), pEventManagerLocator_(pEventManagerLocator) {};
        ~InputTask() final;

    protected:
        void onInitialize() override;
        void onUpdate() override;

    private:
        LPDIRECTINPUT8 mpDI_;
        std::unique_ptr<D3DKeyboard> pD3DKeyboard_ = std::make_unique<D3DKeyboard>();
        iKeyboard* pKeyboard_ = pD3DKeyboard_.get();
        std::unique_ptr<D3DMouse> pD3DMouse_ = std::make_unique<D3DMouse>();
        iMouse* pMouse_ = pD3DMouse_.get();
        iWindowProvider* pWindowProvider_;

        iLocator<iEventManager>* pEventManagerLocator_;
    };
}


#endif // INPUT_TASK_H_
