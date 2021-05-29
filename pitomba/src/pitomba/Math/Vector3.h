
#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <cmath>

namespace pitomba {

    class Vector3 {
    private:
        float x_ = 0.0F;
        float y_ = 0.0F;
        float z_ = 0.0F;

    public:
        Vector3() = default;
        Vector3(const float x, const float y, const float z);
        explicit Vector3(const float value);

        virtual ~Vector3() = default;

        // getters
        float getX() const;
        float getY() const;
        float getZ() const;

        // setters
        void setX(const float x);
        void setY(const float y);
        void setZ(const float z);
        void set(float value);
        void set(float x, float y, float z);

        // operators
        Vector3 operator +(const Vector3& rhs) const;
        Vector3 operator -(const Vector3& rhs) const;
        Vector3 operator *(const Vector3& rhs) const;
        Vector3 operator /(const Vector3& rhs) const;

        Vector3 operator +(const float scalar) const;
        Vector3 operator -(const float scalar) const;
        Vector3 operator *(const float scalar) const;
        Vector3 operator /(const float scalar) const;

        Vector3& operator +=(const Vector3& rhs);
        Vector3& operator -=(const Vector3& rhs);
        Vector3& operator *=(const Vector3& rhs);
        Vector3& operator /=(const Vector3& rhs);

        Vector3& operator +=(const float scalar);
        Vector3& operator -=(const float scalar);
        Vector3& operator *=(const float scalar);
        Vector3& operator /=(const float scalar);

        Vector3 operator -() const;

        bool operator ==(const Vector3& rhs) const;
        bool operator !=(const Vector3& rhs) const;

        // vector operations
        Vector3 cross(const Vector3& rhs) const;
        float dot(const Vector3& rhs) const;
        float lengthSquared() const;
        float length() const;
        void normalise();

        // additional operations
        float distance(const Vector3& v) const;
        float distanceSquared(const Vector3& v) const;
    };

}

#endif // VECTOR3_H_
