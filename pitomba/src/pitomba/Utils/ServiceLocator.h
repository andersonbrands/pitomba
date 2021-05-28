
#ifndef SERVICE_LOCATOR_H_
#define SERVICE_LOCATOR_H_

#include "../EventManager/iEventManager.h"
#include "../Utils/iRng.h"
#include "../Utils/iLogger.h"
#include "../Utils/iTimer.h"
#include "../Utils/iLocator.h"
#include "../Renderer/iRenderer.h"
#include "../Renderer/Texture/iTextureManager.h"

namespace pitomba {

    class ServiceLocator :
        public iLocator<iTimer>,
        public iLocator<iLogger>,
        public iLocator<iRenderer>,
        public iLocator<iEventManager>,
        public iLocator<iTextureManager>,
        public iLocator<iRng> {

    };
}

#endif // SERVICE_LOCATOR_H_
