#include "utils.hpp"

////////////////////////////// CONSTRUCTORS

inline Vector2::Vector2()
        : x(0.f), y(0.f)
{}
inline Vector2::Vector2(const float& _x, const float& _y)
        : x(_x), y(_y)
{}

////////////////////////////// CONSTANTS

inline const Vector2 Vector2::zero = {0.f, 0.f};

////////////////////////////// OPERATORS

template<typename T>
inline Vector2 Vector2::operator*(const T& i_k) const
{
    return {
            x * i_k,
            y * i_k
    };
}
inline Vector2 Vector2::operator*(const Vector2& i_vec) const
{
    return {
            x * i_vec.x,
            y * i_vec.y
    };
}

template<typename T>
inline Vector2 Vector2::operator/(const T& i_k) const
{
    if (i_k == 0.f)
        return { 0.f, 0.f };

    T quotient = 1.f / i_k;

    return {
            x * quotient,
            y * quotient
    };
}
inline Vector2 Vector2::operator/(const Vector2& i_vec) const
{
    return {
            x / i_vec.x,
            y / i_vec.y
    };
}

template<typename T>
inline Vector2 Vector2::operator+(const T& i_k) const
{
    return {
            i_k + x,
            i_k + y
    };
}
inline Vector2 Vector2::operator+(const Vector2& i_vec) const
{
    return {
            x + i_vec.x,
            y + i_vec.y
    };
}

inline Vector2 Vector2::operator-(const Vector2& i_vec) const
{
    return {
            x - i_vec.x,
            y - i_vec.y
    };
}
inline Vector2 Vector2::operator-(const float& i_k) const
{
    return {
            i_k - x,
            i_k - y
    };
}
inline Vector2 Vector2::operator-() const
{
    return {
            -x,
            -y
    };
}

inline Vector2 Vector2::operator+=(Vector2& i_vec)
{
    return {
            x += i_vec.x,
            y += i_vec.y
    };
}

inline Vector2 Vector2::operator-=(Vector2& i_vec)
{
    return {
            x -= i_vec.x,
            y -= i_vec.y
    };
}

inline bool Vector2::operator==(const Vector2& i_vec) const
{
    return (
            x == i_vec.x &&
            y == i_vec.y
    );
}

template<typename T>
inline Vector2& Vector2::operator*=(const T& i_k)
{
    return this *= i_k;
}

inline std::ostream& operator<<(std::ostream& o_o, const Vector2& i_vec)
{
    return o_o << "x = " << i_vec.x << ", y = " << i_vec.y;
}

////////////////////////////// FUNCTIONS

inline Vector2 Vector2::Normalize() const
{
    float length = Length();

    if (length == 0.f)
        return *this;

    return *this / length;
}

inline Vector2 Vector2::Abs() const
{
    return { Maths::Abs(x), Maths::Abs(y) };
}

inline float Vector2::Length() const
{
    return Maths::Sqrt(x * x + y * y);
}

inline float Vector2::SqrLength() const
{
    return x * x + y * y;
}

inline float Vector2::Distance(const Vector2 &i_vecA, const Vector2 &i_vecB)
{
    return Vector2::VecFromPt(i_vecA, i_vecB).Length();
}

inline float Vector2::DotProduct(const Vector2 &i_vecA, const Vector2 &i_vecB)
{
    return i_vecA.x * i_vecB.x + i_vecA.y * i_vecB.y;
}

inline Vector2 Vector2::VecFromPt(const Vector2& i_ptA, const Vector2& i_ptB)
{
    return i_ptB - i_ptA;
}

inline Vector2 Vector2::RightAngleRotation(Vector2& i_vector)
{
    float x = i_vector.x;

    i_vector.x = -i_vector.y;
    i_vector.y = x;

    return i_vector;
}

inline Vector2 Vector2::NormalVector(Vector2& i_vector)
{
    Vector2 rotVect = RightAngleRotation(i_vector);

    return rotVect;
}