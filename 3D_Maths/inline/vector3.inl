#include "quaternion.hpp"
#include "utils.hpp"

////////////////////////////// CONSTRUCTORS

inline Vector3::Vector3()
            : x(0.f), y(0.f), z(0.f)
{}
inline Vector3::Vector3(const float& i_x, const float& i_y, const float& i_z)
            : x(i_x), y(i_y), z(i_z)
{}

////////////////////////////// VARIABLES

inline const Vector3 Vector3::zero = {0.f, 0.f, 0.f};
inline const Vector3 Vector3::right = { 1.f, 0.f, 0.f};
inline const Vector3 Vector3::left = { -1.f, 0.f, 0.f};
inline const Vector3 Vector3::up = { 0.f, 1.f, 0.f};
inline const Vector3 Vector3::down = { 0.f, -1.f, 0.f};
inline const Vector3 Vector3::forward = { 0.f, 0.f, 1.f};
inline const Vector3 Vector3::backward = { 0.f, 0.f, -1.f};

////////////////////////////// OPERATORS

template<typename T>
inline Vector3 Vector3::operator*(const T& i_k) const
{
    return {
            x * i_k,
            y * i_k,
            z * i_k
    };
}

template<typename T>
Vector3 operator*(T i_k, const Vector3& i_v)
{
    return{
            i_v.x * i_k,
            i_v.y * i_k,
            i_v.z * i_k,
    };
}

inline Vector3 Vector3::operator*(const Vector3& i_vec) const
{
    return {
            x * i_vec.x,
            y * i_vec.y,
            z * i_vec.z
    };
}

template<typename T>
inline Vector3 Vector3::operator/(const T& i_k) const
{
    if (i_k == 0.f)
        return { 0.f, 0.f, 0.f };

    T quotient = 1.f / i_k;

    return {
            x * quotient,
            y * quotient,
            z * quotient
    };
}
inline Vector3 Vector3::operator/(const Vector3& i_vec) const
{
    return {
            x / i_vec.x,
            y / i_vec.y,
            z / i_vec.z
    };
}

template<typename T>
inline Vector3 Vector3::operator+(const T& i_k) const
{
    return {
            i_k + x,
            i_k + y,
            i_k + z
    };
}
inline Vector3 Vector3::operator+(const Vector3& i_vec) const
{
    return {
            x + i_vec.x,
            y + i_vec.y,
            z + i_vec.z
    };
}

inline Vector3 Vector3::operator-(const Vector3& i_vec) const
{
    return {
            x - i_vec.x,
            y - i_vec.y,
            z - i_vec.z
    };
}
inline Vector3 Vector3::operator-(const float& i_k) const
{
    return {
            i_k - x,
            i_k - y,
            i_k - z
    };
}
inline Vector3 Vector3::operator-() const
{
    return {
            -x,
            -y,
            -z
    };
}

inline Vector3 Vector3::operator^(const Vector3& i_vec) const // Cross product
{
    return
            {
                    y * i_vec.z - z * i_vec.y,
                    z * i_vec.x - x * i_vec.z,
                    x * i_vec.y - y * i_vec.x
            };
}

inline Vector3 Vector3::operator+=(const Vector3& i_vec)
{
    return {
            x += i_vec.x,
            y += i_vec.y,
            z += i_vec.z
    };
}

inline Vector3 Vector3::operator-=(const Vector3& i_vec)
{
    return {
            x -= i_vec.x,
            y -= i_vec.y,
            z -= i_vec.z
    };
}

inline bool Vector3::operator==(const Vector3& i_vec) const
{
    return (
            Maths::Abs(x - i_vec.x) < Maths::Constants::weakEpsilon &&
            Maths::Abs(y - i_vec.y) < Maths::Constants::weakEpsilon &&
            Maths::Abs(z - i_vec.z) < Maths::Constants::weakEpsilon
    );
}

template<typename T>
inline Vector3& Vector3::operator*=(const T& i_k)
{
    return this *= i_k;
}

inline std::ostream& operator<<(std::ostream& o_o, const Vector3& i_vec)
{
    return o_o << "x = " << i_vec.x << ", y = " << i_vec.y << ", z = " << i_vec.z;
}

////////////////////////////// FUNCTIONS

inline Vector3 Vector3::Normalize() const
{
    float length = Length();

    if (length == 0.f)
        return *this;

    return *this / length;
}

inline Vector3 Vector3::Abs() const
{
    return { Maths::Abs(x), Maths::Abs(y), Maths::Abs(z) };
}

inline float Vector3::Length() const
{
    return Maths::Sqrt(x * x + y * y + z * z);
}

inline float Vector3::SqrLength() const
{
    return x * x + y * y + z * z;
}

inline float Vector3::Distance(const Vector3& i_vecA, const Vector3& i_vecB)
{
    return Vector3::VecFromPt(i_vecA, i_vecB).Length();
}

inline float Vector3::DotProduct(const Vector3& i_vecA, const Vector3& i_vecB)
{
    return i_vecA.x * i_vecB.x + i_vecA.y * i_vecB.y + i_vecA.z * i_vecB.z;
}

inline Vector3 Vector3::CrossProduct(const Vector3& i_vecA, const Vector3& i_vecB)
{
    return i_vecA ^ i_vecB;
}

inline Vector3 Vector3::VecFromPt(const Vector3& i_ptA, const Vector3& i_ptB)
{
    return i_ptB - i_ptA;
}

inline Vector3 Vector3::RotateByQuat(const Vector3& i_v, const Quaternion& i_q)
{
    Vector3 result = zero;

    Quaternion n_q = i_q.Normalize();

    result.x = i_v.x * (n_q.w * n_q.w + n_q.x * n_q.x - n_q.y * n_q.y - n_q.z * n_q.z)	+ i_v.y * (2 * (n_q.x * n_q.y) - 2 * (n_q.w * n_q.z))					        + i_v.z * (2 * (n_q.x * n_q.z) + 2 * (n_q.w * n_q.y));
    result.y = i_v.x * (2 * (n_q.x * n_q.y) + 2 * (n_q.w * n_q.z))				        + i_v.y * (n_q.w * n_q.w + n_q.y * n_q.y - n_q.x * n_q.x - n_q.z * n_q.z)		+ i_v.z * (2 * (n_q.y * n_q.z) - 2 * (n_q.w * n_q.x));
    result.z = i_v.x * (2 * (n_q.x * n_q.z) - 2 * (n_q.w * n_q.y))				        + i_v.y * (2 * (n_q.y * n_q.z) + 2 * (n_q.w * n_q.x))					        + i_v.z * (n_q.w * n_q.w + n_q.z * n_q.z - n_q.x * n_q.x - n_q.y * n_q.y);

    return result;
}