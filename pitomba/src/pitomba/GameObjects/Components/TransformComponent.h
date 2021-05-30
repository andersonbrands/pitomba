
#ifndef TRANSFORM_COMPONENT_H_
#define TRANSFORM_COMPONENT_H_

#include "../Component.h"
#include "../ComponentId.h"
#include "../../Math/Transform.h"


namespace pitomba {

    class TransformComponent : public Component, public Transform {
    public:
        static ComponentId getId() {
            return component::TRANSFORM;
        }

        using Component::Component;

        ~TransformComponent() final = default;

    };
}

#endif // TRANSFORM_COMPONENT_H_
