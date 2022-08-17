#include "vector3.hpp"
#include "vector4.hpp"

#include "constants.hpp"

namespace Maths {

    inline float ToRadians(const float& i_degAngle)
    {
        return i_degAngle * (Constants::pi / 180.f);
    }

    inline Vector3 ToRadians(const Vector3& i_degAngles)
    {
        return i_degAngles * (Constants::pi / 180.f);
    }

    inline float ToDegrees(const float& i_radAngle)
    {
        return i_radAngle * (180.f / Constants::pi);
    }

    inline Vector3 ToDegrees(const Vector3& i_radAngles)
    {
        return i_radAngles * (180.f / Constants::pi);
    }

    template<typename T>
    inline T Min(const T& i_a, const T& i_b)
    {
        return i_a < i_b ? i_a : i_b;
    }

    template<typename T>
    inline T Max(const T& i_a, const T& i_b)
    {
        return i_a > i_b ? i_a : i_b;
    }

    template<typename T>
    inline T Min(const T& i_a, const T& i_b, const T& i_c)
    {
        return Min(Min(i_a, i_b), i_c);
    }

    template<typename T>
    inline T Max(const T& i_a, const T& i_b, const T& i_c)
    {
        return Max(Max(i_a, i_b), i_c);
    }

    template<typename T>
    inline T Clamp(const T& i_val, const T& i_min, const T& i_max)
    {
        return Max(Min(i_val, i_max), i_min);
    }

    inline int Modulo(const int i_val, const int i_base)
    {
        return i_val % i_base;
    }

    inline float Modulo(const float& i_val, const float& i_base)
    {
        return fmod(i_val, i_base);
    }

    inline Vector3 Modulo(const Vector3& i_val, const float& i_base)
    {
        return {
                Modulo(i_val.x, i_base),
                Modulo(i_val.y, i_base),
                Modulo(i_val.z, i_base)
        };
    }

    inline float Abs(const float& i_f)
    {
        return fabs(i_f);
    }

    inline float Sqrt(const float& i_f)
    {
        return sqrtf(i_f);
    }

    inline float Square(const float& i_f)
    {
        return i_f * i_f;
    }

    inline float Cos(const float& i_f)
    {
        return cosf(i_f);
    }

    inline float Acos(const float& i_f)
    {
        return acosf(i_f);
    }

    inline float Sin(const float& i_f)
    {
        return sinf(i_f);
    }

    inline float Asin(const float& i_f)
    {
        return asinf(i_f);
    }

    inline float Tan(const float& i_f)
    {
        return tanf(i_f);
    }

    inline float Atan(const float& i_f)
    {
        return atanf(i_f);
    }

    inline float Atan2(const float& i_f1, const float& i_f2)
    {
        return atan2(i_f1, i_f2);
    }

    template<typename T>
    inline T Lerp(const T& i_start, const T& i_reach, float& i_factor)
    {
        i_factor = Clamp(i_factor, -1.f, 1.f);
        return i_start + i_factor * (i_reach - i_start);
    }

    template<typename T>
    inline int Sign(const T& i_val)
    {
        return (T(0) < i_val) - (i_val < T(0));
    }
}
