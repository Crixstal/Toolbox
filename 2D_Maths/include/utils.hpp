#pragma once

#include <cmath>

namespace Maths
{
    struct Constants
    {
        static constexpr float pi = 3.14159265358979323846264f;
        static constexpr float epsilon = 1e-24f;
    };

/**
 * @returns a float's absolute value
 */
    float Abs(float i_f);

/**
 * @returns a float's square root
 */
    float Sqrt(float i_f);
}

#include "utils.inl"