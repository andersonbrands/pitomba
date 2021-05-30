
#ifndef MATRIX_4_H_
#define MATRIX_4_H_

#include "Vector3.h"

namespace pitomba {

    class Matrix4 {
    private:
        float m_[16];
    public:

        Matrix4();
        Matrix4(const Vector3& col1, const Vector3& col2, const Vector3& col3, const Vector3& col4);
        ~Matrix4() = default;

        void identify();

        float get(int index) const {
            return m_[index];
        }

        // operators
        Matrix4 operator *(const Matrix4& rhs) const;
        Vector3 operator *(const Vector3& rhs) const;
        Matrix4& operator *=(const Matrix4& rhs);
    };
}

#endif // MATRIX_4_H_
