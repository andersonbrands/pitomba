
#include "AABBCollider.h"

namespace pitomba {

    AABBCollider::AABBCollider(Transform* pTransform, const Vector3& min, const Vector3& max) : pTransform_(pTransform), min_(min), max_(max) {

    }

    bool AABBCollider::collides(const AABBCollider& bb) const {
        bool collides(true);

        Vector3 max(getMax());
        Vector3 min(getMin());
        Vector3 max2(bb.getMax());
        Vector3 min2(bb.getMin());

        if (min.getX() > max2.getX() ||
            min.getY() > max2.getY() ||
            min.getZ() > max2.getZ() ||

            max.getX() < min2.getX() ||
            max.getY() < min2.getY() ||
            max.getZ() < min2.getZ()) {

            collides = false;

        }

        return collides;
    }

}
