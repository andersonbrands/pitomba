
#include "InputTask.h"
#include <dinput.h>
#include "../EventManager/EventId.h"
#include "../EventManager/EventData.h"


namespace pitomba {
    InputTask::~InputTask() {
        if (mpDI_) {
            mpDI_->Release();
            mpDI_ = nullptr;
        }
    }

    void InputTask::onInitialize() {
        // Create the DirectInput object.
        auto result = DirectInput8Create(pWindowProvider_->getHInstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&mpDI_, nullptr);

        if (FAILED(result)) {
            MessageBox(nullptr, L"DInput8Create failed", L"Error", MB_OK);
        }

        pD3DKeyboard_->initialize(mpDI_, pWindowProvider_->getWindow());
        pD3DMouse_->initialize(mpDI_, pWindowProvider_->getWindow());

        pEventManagerLocator_->get()->registerEvent(ev::id::INPUT_UPDATED);
    }

    void InputTask::onUpdate() {
        pD3DKeyboard_->update();
        pD3DMouse_->update();

        auto data = ev::data::InputUpdated{ pKeyboard_, pMouse_ };
        pEventManagerLocator_->get()->sendEvent(ev::id::INPUT_UPDATED, &data);
    }

}
