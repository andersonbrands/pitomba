
#include "Vector3.h"

namespace pitomba {

    Vector3::Vector3(const float x, const float y, const float z) :
        x_(x), y_(y), z_(z) {}

    Vector3::Vector3(const float value) :
        x_(value), y_(value), z_(value) {}

    // getters
    float Vector3::getX() const {
        return x_;
    }
    float Vector3::getY() const {
        return y_;
    }
    float Vector3::getZ() const {
        return z_;
    }

    // setters
    void Vector3::setX(const float x) {
        x_ = x;
    }
    void Vector3::setY(const float y) {
        y_ = y;
    }
    void Vector3::setZ(const float z) {
        z_ = z;
    }

    void Vector3::set(float value) {
        x_ = y_ = z_ = value;
    }
    void Vector3::set(float x, float y, float z) {
        x_ = x;
        y_ = y;
        z_ = z;
    }

    // operators
    Vector3 Vector3::operator +(const Vector3& rhs) const {
        return Vector3(x_ + rhs.x_, y_ + rhs.y_, z_ + rhs.z_);
    }
    Vector3 Vector3::operator -(const Vector3& rhs) const {
        return Vector3(x_ - rhs.x_, y_ - rhs.y_, z_ - rhs.z_);
    }
    Vector3 Vector3::operator *(const Vector3& rhs) const {
        return Vector3(x_ * rhs.x_, y_ * rhs.y_, z_ * rhs.z_);
    }
    Vector3 Vector3::operator /(const Vector3& rhs) const {
        return Vector3(x_ / rhs.x_, y_ / rhs.y_, z_ / rhs.z_);
    }

    Vector3 Vector3::operator +(const float scalar) const {
        return Vector3(x_ + scalar, y_ + scalar, z_ + scalar);
    }
    Vector3 Vector3::operator -(const float scalar) const {
        return Vector3(x_ - scalar, y_ - scalar, z_ - scalar);
    }
    Vector3 Vector3::operator *(const float scalar) const {
        return Vector3(x_ * scalar, y_ * scalar, z_ * scalar);
    }
    Vector3 Vector3::operator /(const float scalar) const {
        return Vector3(x_ / scalar, y_ / scalar, z_ / scalar);
    }

    Vector3& Vector3::operator +=(const Vector3& rhs) {
        x_ += rhs.x_;
        y_ += rhs.y_;
        z_ += rhs.z_;

        return *this;
    }
    Vector3& Vector3::operator -=(const Vector3& rhs) {
        x_ -= rhs.x_;
        y_ -= rhs.y_;
        z_ -= rhs.z_;

        return *this;
    }
    Vector3& Vector3::operator *=(const Vector3& rhs) {
        x_ *= rhs.x_;
        y_ *= rhs.y_;
        z_ *= rhs.z_;

        return *this;
    }
    Vector3& Vector3::operator /=(const Vector3& rhs) {
        x_ /= rhs.x_;
        y_ /= rhs.y_;
        z_ /= rhs.z_;

        return *this;
    }

    Vector3& Vector3::operator +=(const float scalar) {
        x_ += scalar;
        y_ += scalar;
        z_ += scalar;

        return *this;
    }
    Vector3& Vector3::operator -=(const float scalar) {
        x_ -= scalar;
        y_ -= scalar;
        z_ -= scalar;

        return *this;
    }
    Vector3& Vector3::operator *=(const float scalar) {
        x_ *= scalar;
        y_ *= scalar;
        z_ *= scalar;

        return *this;
    }
    Vector3& Vector3::operator /=(const float scalar) {
        x_ /= scalar;
        y_ /= scalar;
        z_ /= scalar;

        return *this;
    }

    Vector3 Vector3::operator -() const {
        return Vector3(-x_, -y_, -z_);
    }

    bool Vector3::operator ==(const Vector3& rhs) const {
        if (x_ == rhs.x_ && y_ == rhs.y_ && z_ == rhs.z_)
            return true;
        else
            return false;
    }
    bool Vector3::operator !=(const Vector3& rhs) const {
        return !(*this == rhs);
    }

    // vector operations
    Vector3 Vector3::cross(const Vector3& rhs) const {
        return Vector3(y_ * rhs.z_ - z_ * rhs.y_, z_ * rhs.x_ - x_ * rhs.z_, x_ * rhs.y_ - y_ * rhs.x_);
    }

    float Vector3::dot(const Vector3& rhs) const {
        return (x_ * rhs.x_ + y_ * rhs.y_ + z_ * rhs.z_);
    }

    float Vector3::lengthSquared() const {
        return (x_ * x_ + y_ * y_ + z_ * z_);
    }

    float Vector3::length() const {
        return sqrt(lengthSquared());
    }

    void Vector3::normalise() {
        float len(length());

        if (len != 0.0f) {
            *this /= len;
        }
    }

    float Vector3::distance(const Vector3& v) const {
        return sqrt(distanceSquared(v));
    }

    float Vector3::distanceSquared(const Vector3& v) const {
        float dX(x_ - v.x_);
        float dY(y_ - v.y_);

        return dX * dX + dY * dY;
    }


}