#pragma once

struct Vector2 {
    union {
        struct { float x; float y; };

        float element[2]{};
    };

////////////////////////////// CONSTRUCTORS

    Vector2();
    Vector2(const float& i_x, const float& i_y);

////////////////////////////// CONSTANTS

    static const Vector2 zero;

////////////////////////////// OPERATORS

    template<typename T>
    Vector2 operator*(const T& i_k) const;
    Vector2 operator*(const Vector2& i_vec) const;

    template<typename T>
    Vector2 operator/(const T& i_k) const;
    Vector2 operator/(const Vector2& i_vec) const;

    template<typename T>
    Vector2 operator+(const T& i_k) const;
    Vector2 operator+(const Vector2& i_vec) const;

    Vector2 operator-(const Vector2& i_vec) const;
    Vector2 operator-(const float& i_k) const;
    Vector2 operator-() const;

    Vector2 operator+=(Vector2& i_vec);

    Vector2 operator-=(Vector2& i_vec);

    bool operator==(const Vector2& i_vec) const;

    template<typename T>
    Vector2 &operator*=(const T& i_k);

////////////////////////////// FUNCTIONS

/**
 * @returns a vector with same direction but length = 1
 */
    Vector2 Normalize() const;

/**
 * @returns vector's absolute values
 */
    Vector2 Abs() const;

/**
 * @returns vector's length/magnitude
 */
    float Length() const;

    /**
 * @returns vector's square length/magnitude
 */
    float SqrLength() const;

/**
 * @returns the distance between two vectors
 */
    static float Distance(const Vector2 &i_vecA, const Vector2 &i_vecB);

/**
 * @returns dot product of two vectors.
 * If the vectors have the same direction the dot product return 1
 * If the vectors are orthogonal the dot product return 0
 * If the vectors have the opposite direction dot product return -1
 */
    static float DotProduct(const Vector2 &i_vecA, const Vector2 &i_vecB);

/**
 * @returns
 * the vector which starts from point A and end at point B,
 * equivalent to AB vector
 */
    static Vector2 VecFromPt(const Vector2 &i_ptA, const Vector2 &i_ptB);

    static Vector2 RightAngleRotation(Vector2& i_vector);

    static Vector2 NormalVector(Vector2& i_vector);
};

std::ostream& operator<<(std::ostream& o_o, const Vector2& i_vec);

#include "vector2.inl"