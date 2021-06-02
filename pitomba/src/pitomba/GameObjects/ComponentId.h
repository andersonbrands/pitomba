#ifndef COMPONENT_ID_H_
#define COMPONENT_ID_H_

namespace pitomba {

    using ComponentId = unsigned int;

    namespace component {
        //static const ComponentId COMPONENT_ID_COMPONENT_NAME = value;
        static const ComponentId SPRITE = 0;
        static const ComponentId SPRITE_ANIMATION = 1;
        static const ComponentId TRANSFORM = 2;
    }

}

#endif // COMPONENT_ID_H_
