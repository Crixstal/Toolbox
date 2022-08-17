#pragma once

struct Vector3;
struct Vector4;

namespace Maths
{
    /**
     *
     * @param i_degreeAngle an angle in degrees
     * @return the angle converted from degrees to radians
     */
    float ToRadians(const float& i_degAngle);

    /**
     *
     * @param i_radAngle an angle in radians
     * @return the angle converted from radians to degrees
     */
    float ToDegrees(const float& i_radAngle);

    /**
     *
     * @param i_degAngles three angles in degrees
     * @return the angles converted from degrees to radians
     */
    Vector3 ToRadians(const Vector3& i_degAngles);

    /**
     *
     * @param i_radAngles three angles in radians
     * @return the angles converted from radians to degrees
     */
    Vector3 ToDegrees(const Vector3& i_radAngles);

    /**
     * @summary Return minimum between two values, negative numbers accepted
     */
    template<typename T>
    T Min(const T& i_a, const T& i_b);

    /**
     * @summary Return maximum between two values, negative numbers accepted
     */
    template<typename T>
    T Max(const T& i_a, const T& i_b);

    /**
     * @summary Return minimum between three values, negative numbers accepted
     */
    template<typename T>
    T Min(const T& i_a, const T& i_b, const T& i_c);

    /**
     * @summary Return maximum between three values, negative numbers accepted
     */
    template<typename T>
    T Max(const T& i_a, const T& i_b, const T& i_c);

    /**
     * @summary Avoid a variable value to be outside of a range, negative numbers accepted
     */
    template<typename T>
    T Clamp(const T& i_val, const T& i_min, const T& i_max);

    /**
     * @summary Loops an int value in a range, so that it is never larger than the range and never smaller than 0.
     * @param i_val the value to loop, else the divident
     * @param i_range the value which defines the maximum value of the loop, else the divisor
     * @return the rest of an euclidien division.
     */
    int Modulo(const int i_val, const int i_range);

    /**
     * @summary Loops a float value in a range, so that it is never larger than the range and never smaller than 0.
     * @param i_val the value to loop, else the divident
     * @param i_range the value which defines the maximum value of the loop, else the divisor
     * @return the rest of an euclidien division.
     */
    float Modulo(const float& i_val, const float& i_range);

    /**
     * @summary Return a float's absolute value
     */
    float Abs(const float& i_f);

    /**
     * @summary Return a float's square root
     */
    float Sqrt(const float& i_f);

    /**
     * @summary Return a float's square, negative numbers accepted
     */
    float Square(const float& i_f);

    /**
     * @summary Return a float's cosine, negative numbers accepted
     * @param i_f   float in radian
     */
    float Cos(const float& i_f);

    /**
     * @summary Return a float's arccosine
     * @param i_f   float in radian
     */
    float Acos(const float& i_f);

    /**
     * @summary Return a float's sine
     * @param i_f   float in radian
     */
    float Sin(const float& i_f);

    /**
     * @summary Return a float's arcsine
     * @param i_f   float in radian
     */
    float Asin(const float& i_f);

    /**
     * @summary Return a float's tangent
     * @param i_f   float in radian
     */
    float Tan(const float& i_f);

    /**
     * @summary Return a float's arctangent
     * @param i_f float in radian
     */
    float Atan(const float& i_f);

    /**
     * @summary Return two float's arctangent
     * @param i_f1 float in radian
     * @param i_f2 float in radian
     */
    float Atan2(const float& i_f1, const float& i_f2);

    /**
     * @summary Linearly interpolates between i_start and i_reach by i_factor
     * @return The interpolated float result between the two float values
     * @param i_factor clamped to the range [-1, 1]
     */
    template<typename T>
    T Lerp(const T& i_start, const T& i_reach, float& i_factor);

    /**
     * @summary Define the sign of a number, positive or negative
     * @returns 1 if the number is positive,
     *          -1 if the number is negative
     */
    template <typename T>
    int Sign(const T& i_val);
}

#include "utils.inl"