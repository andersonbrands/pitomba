
#include "GameObject.h"

namespace pitomba {


    GameObject::~GameObject() {
        for (ComponentUnorderedMapIterator iter = components_.begin(); iter != components_.end(); ++iter) {
            Component* pComponent = iter->second;
            if (pComponent) {
                delete pComponent;
                pComponent = nullptr;
            }
        }
    }

    Component* GameObject::getComponent(ComponentId id) const {
        auto result = components_.find(id);
        return result == components_.end() ? nullptr : result->second;
    }


}