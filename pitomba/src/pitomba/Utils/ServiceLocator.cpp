
#include "ServiceLocator.h"

namespace pitomba {

    iEventManager* ServiceLocator::eventManager_ = nullptr;
    iRng* ServiceLocator::rng_ = nullptr;
    iTimer* ServiceLocator::timer_ = nullptr;
    iRenderer* ServiceLocator::renderer_ = nullptr;

}