
#ifndef COMPONENT_H_
#define COMPONENT_H_

namespace pitomba {
    class GameObject;

    class Component {
    private:
        GameObject* pOwner_;

    public:
        explicit Component(GameObject* pOwner)
            : pOwner_(pOwner) {}

        virtual ~Component() = default;

        GameObject* getOwner() const {
            return pOwner_;
        }
    };
}

#endif // COMPONENT_H_
