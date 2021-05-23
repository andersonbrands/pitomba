
#include "ServiceLocator.h"

namespace pitomba {

    std::shared_ptr<iEventManager> ServiceLocator::eventManager_ = nullptr;
    std::shared_ptr<iRng> ServiceLocator::rng_ = nullptr;

}