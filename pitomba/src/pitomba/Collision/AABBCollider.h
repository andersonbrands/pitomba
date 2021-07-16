
#ifndef AABB_COLLIDER_H_
#define AABB_COLLIDER_H_

#include "../Math/Vector3.h"
#include "../Math/Transform.h"

namespace pitomba {

    class AABBCollider {
    private:
        Transform* pTransform_;
        Vector3 min_;
        Vector3 max_;
    public:
        AABBCollider(Transform* pTransform, const Vector3& min, const Vector3& max);
        ~AABBCollider() = default;


        bool collides(const AABBCollider&) const;

        Vector3 getMin() const {
            Vector3 pos(pTransform_->getTranslation());
            return min_ + pos;
        }

        Vector3 getMax() const {
            Vector3 pos(pTransform_->getTranslation());
            return max_ + pos;
        }
    };

}

#endif // AABB_COLLIDER_H_
