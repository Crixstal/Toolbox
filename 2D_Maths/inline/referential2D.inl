#include "vector2.hpp"

////////////////////////////// CONSTRUCTORS

inline Referential2D::Referential2D()
{
    origin = Vector2(0.f, 0.f);

    i = Vector2(1.f, 0.f);
    j = Vector2(0.f, 1.f);
}

inline Referential2D::Referential2D(const Vector2& _origin, const Vector2& _i, const Vector2& _j)
{
    origin = _origin;

    i = _i;
    j = _j;
}

////////////////////////////// OPERATORS

inline std::ostream& operator<<(std::ostream& o_o, const Referential2D& i_ref)
{
    return o_o << "origin : " << i_ref.origin << '\n'
             << "i : " << i_ref.i << '\n'
             << "j : " << i_ref.j;
}

////////////////////////////// FUNCTIONS

inline Vector2 Referential2D::PosLocalToGlobal(const Vector2& i_localPos) const
{
    return origin + (i * i_localPos.x) + (j * i_localPos.y);
}

inline Vector2 Referential2D::PosGlobalToLocal(const Vector2& i_globalPos) const
{
    Vector2 originToPos = i_globalPos - origin;

    return {
            Vector2::DotProduct(originToPos, i),
            Vector2::DotProduct(originToPos, j)
    };
}

inline Vector2 Referential2D::VectLocalToGlobal(const Vector2& i_localVect) const
{
    return (i * i_localVect.x) + (j * i_localVect.y);
}

inline Vector2 Referential2D::VectGlobalToLocal(const Vector2& i_globalVect) const
{
    return {
            Vector2::DotProduct(i_globalVect, i),
            Vector2::DotProduct(i_globalVect, j)
    };
}