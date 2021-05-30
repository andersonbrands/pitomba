
#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Vector3.h"
#include "Matrix4.h"
#include <math.h>

namespace pitomba {

    class Matrix4;

    class Transform {
    public:
        Transform() = default;
        virtual ~Transform() = default;

        void clone(const Transform& transform);

        void rotate(const Vector3& rotation);
        void scale(const Vector3& rotation);
        void translate(const Vector3& rotation);

        void setRotation(const Vector3& rotation);
        const Vector3& getRotation() const;

        void setTranslation(const Vector3& translation);
        const Vector3& getTranslation() const;

        void setScale(const Vector3& scale);
        const Vector3& getScale() const;

        const Matrix4& getMatrix();
    private:
        Vector3 rotation_ = Vector3(0.0F);
        Vector3 translation_ = Vector3(0.0F);
        Vector3 scale_ = Vector3(1.0F);
        Matrix4 matrix_;

        void applyRotation();
        void applyScale();
        void applyTranslation();

        void setMatrix();
    };

}
#endif // TRANSFORM_H_ 
