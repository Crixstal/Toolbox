#pragma once

struct Vector2;

struct Referential2D {
    Vector2 origin;
    Vector2 i, j;

////////////////////////////// CONSTRUCTORS

    Referential2D();
    Referential2D(const Vector2& i_origin, const Vector2& i_i, const Vector2& i_j);

////////////////////////////// FUNCTIONS

/**
 * @summary Convert position from local to global referential
 * @return global position of the input position
 * @warning this method consider a position, not a translation vector
 */
    Vector2 PosLocalToGlobal(const Vector2& i_localPos) const;

/**
 * @summary Convert position from global to local referential
 * @return local position of the input position
 * @warning this method consider a position, not a translation vector
 */
    Vector2 PosGlobalToLocal(const Vector2& i_globalPos) const;

/**
 * @summary Convert vector from local to global referential
 * @return global vector of the input vector
 * @warning this method consider a translation vector, not a position
 */
    Vector2 VectLocalToGlobal(const Vector2& i_localVect) const;

/**
 * @summary Convert vector from global to local referential
 * @return local vector of the input vector
 * @warning this method consider a translation vector, not a position
 */
    Vector2 VectGlobalToLocal(const Vector2& i_globalVect) const;
};

std::ostream& operator<<(std::ostream& o_o, const Referential2D& i_ref);

#include "referential2D.inl"