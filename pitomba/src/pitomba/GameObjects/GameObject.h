
#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <unordered_map>
#include "Component.h"
#include "ComponentId.h"


namespace pitomba {

    class GameObject {
    public:
        GameObject() = default;
        virtual ~GameObject();

        void setActive(bool active) {
            active_ = active;
        }
        bool isActive() const {
            return active_;
        }

        template <class T>
        bool add();

        template <class T>
        T* get() const {
            return static_cast<T*>(getComponent(T::getId()));
        }

    private:
        using ComponentUnorderedMap = std::unordered_map<ComponentId, Component*>;
        using ComponentUnorderedMapIterator = ComponentUnorderedMap::iterator;

        ComponentUnorderedMap components_;

        Component* getComponent(ComponentId id) const;

        bool active_ = false;

    };

    template <class T>
    bool GameObject::add() {
        bool added = false;

        ComponentUnorderedMapIterator result = components_.find(T::getId());
        if (result == components_.end()) {
            T* pNewComponent = new T(this);

            if (pNewComponent) {
                std::pair<ComponentId, Component*> newComponent(T::getId(), pNewComponent);
                std::pair<ComponentUnorderedMapIterator, bool> addedIter = components_.insert(newComponent);
                added = addedIter.second;
            }
        }
        return added;
    }
}

#endif // GAME_OBJECT_H_
