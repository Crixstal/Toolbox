#include "vector2.hpp"
#include "shape.hpp"

////////////////////////////// CONSTRUCTORS

inline Range::Range()
        : min(0.f), max(0.f)
{}
inline Range::Range(const float& _min, const float& _max)
        : min(_min), max(_max)
{}

////////////////////////////// FUNCTIONS

inline float Range::GetMin(const float& i_a, const float& i_b) const
{
    if (i_a < i_b)
        return i_a;
    else
        return i_b;
}

inline float Range::GetMax(const float& i_a, const float& i_b) const
{
    if (i_a > i_b)
        return i_a;
    else
        return i_b;
}

inline Range Range::GlobalRange(const Range& i_rng1, const Range& i_rng2) const
{
    Range globalRng;

    globalRng.min = GetMin(i_rng1.min, i_rng2.min);
    globalRng.max = GetMax(i_rng1.max, i_rng2.max);

    return globalRng;
}

inline Range Range::GlobRngVal(const Range& i_rng, const float& i_a) const
{
    Range globRngVal;

    globRngVal.min = GetMin(i_rng.min, i_a);
    globRngVal.max = GetMax(i_rng.max, i_a);

    return globRngVal;
}

inline bool Range::RangeOverlap(const Range& i_rng1, const Range& i_rng2) const
{
    if (i_rng1.min > i_rng2.max || i_rng2.min > i_rng1.max)
        return false;

    return true;
}

inline Range Range::PtOnAxisRng(const Vector2& i_pt, const Vector2& i_vect) const
{
    float num = Vector2::DotProduct(i_pt, i_vect);
    Range rng = { num, num };

    return rng;
}

inline Range Range::SegOnAxisRng(const Segment& i_seg, const Vector2& i_vect) const
{
    float min, max;
    Vector2 vectPt1 = { i_seg.pt1.x, i_seg.pt1.y };
    float num1 = Vector2::DotProduct(vectPt1, i_vect);
    Vector2 vectPt2 = { i_seg.pt2.x, i_seg.pt2.y };
    float num2 = Vector2::DotProduct(vectPt2, i_vect);

    if (num1 <= num2)
    {
        min = num1;
        max = num2;
    }
    else
    {
        min = num2;
        max = num1;
    }

    Range rng = { min, max };

    return rng;
}

inline Range Range::BoxOnAxisRng(const Rect& i_box, const Vector2& i_vect) const
{
    Vector2 pt = { i_box.center.x + i_box.halfWidth, i_box.center.y + i_box.halfHeight };
    Vector2 pt1 = { i_box.center.x - i_box.halfWidth, i_box.center.y + i_box.halfHeight };
    Vector2 pt2 = { i_box.center.x - i_box.halfWidth, i_box.center.y - i_box.halfHeight };
    Vector2 pt3 = { i_box.center.x + i_box.halfWidth, i_box.center.y - i_box.halfHeight };

    Vector2 vect1 = { pt.x, pt.y };
    Vector2 vect2 = { pt1.x, pt1.y };
    Vector2 vect3 = { pt2.x, pt2.y };
    Vector2 vect4 = { pt3.x, pt3.y };

    float num = Vector2::DotProduct(i_vect, i_vect);
    float num1 = Vector2::DotProduct(vect1, i_vect);
    float num2 = Vector2::DotProduct(vect2, i_vect);
    float num3 = Vector2::DotProduct(vect3, i_vect);

    float min = GetMin(num, num1);
    float min1 = GetMin(num2, num3);
    float minR = GetMin(min, min1);

    float max = GetMax(num, num1);
    float max1 = GetMax(num2, num3);
    float maxR = GetMax(max, max1);

    Range rng = { minR, maxR };

    return rng;
}