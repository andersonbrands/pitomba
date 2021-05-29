
#ifndef SERVICE_LOCATOR_H_
#define SERVICE_LOCATOR_H_

#include "../Utils/iLocator.h"

#include "../Utils/iRng.h"
#include "../Utils/iTimer.h"
#include "../Utils/iLogger.h"
#include "../Renderer/iRenderer.h"
#include "../Renderer/Texture/iTextureContainer.h"
#include "../EventManager/iEventManager.h"

namespace pitomba {

    class ServiceLocator :
        public iLocator<iRng>,
        public iLocator<iTimer>,
        public iLocator<iLogger>,
        public iLocator<iRenderer>,
        public iLocator<iTextureContainer>,
        public iLocator<iEventManager> {

    };
}

#endif // SERVICE_LOCATOR_H_
