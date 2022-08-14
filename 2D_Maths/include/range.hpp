#pragma once

struct Vector2;
struct Segment;
struct Rect;

struct Range {
    union {
        struct { float min; float max; };

        float element[2]{};
    };

////////////////////////////// CONSTRUCTORS

    Range();
    Range(const float& i_min, const float& i_max);

////////////////////////////// FUNCTIONS

/**
 * @returns the minimum between two values
 */
    float GetMin(const float& i_a, const float& i_b) const;

/**
 * @returns the maximum between two values
 */
    float GetMax(const float& i_a, const float& i_b) const;

/**
 * @returns the global range between two ranges
 */
    Range GlobalRange(const Range& i_rng1, const Range& i_rng2) const;

/**
 * @returns the global range between a range and a value
 */
    Range GlobRngVal(const Range& i_rng, const float& i_a) const;

/**
 * @returns true if two ranges are overlapping
 */
    bool RangeOverlap(const Range& i_rng1, const Range& i_rng2) const;

    Range PtOnAxisRng(const Vector2& i_pt, const Vector2& i_vect) const;

    Range SegOnAxisRng(const Segment& i_seg, const Vector2& i_vect) const;

    Range BoxOnAxisRng(const Rect& i_box, const Vector2& i_vect) const;
};

std::ostream& operator<<(std::ostream& o_o, const Range& i_ref);

#include "range.inl"