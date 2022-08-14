#include "vector2.hpp"

inline bool Line::Line_Line(Line line1, Line line2) const
{
    Vector2 n2 = { -line2.vectDir.y, line2.vectDir.x };

    if (Vector2::DotProduct(n2, line1.vectDir) != 0)
        return true;
    else // check if parallel or coincide
        return false;
}

inline bool Line::Line_Segment(Line line1, Segment seg) const
{
    Vector2 vectAP1 = { seg.pt1.x - line1.base.x, seg.pt1.y - line1.base.y };
    Vector2 vectAP2 = { seg.pt2.x - line1.base.x, seg.pt2.y - line1.base.y };
    Vector2 vectN = { line1.vectDir.y, line1.vectDir.x };

    if (Vector2::DotProduct(vectAP1, vectN) * Vector2::DotProduct(vectAP2, vectN) > 0)
        return true;
    else
    {
        Line line2 = { seg.pt1, {seg.pt2.x - seg.pt1.x, seg.pt2.y - seg.pt1.y} };
        return Line_Line(line1, line2);
    }
}


inline bool Circle::Circle_Circle(Circle circle1, Circle circle2) const
{
    float centers_distance = Vector2::Distance(circle1.center, circle2.center);
    return centers_distance <= circle1.radius + circle2.radius;
}


inline bool Point_Point(Vector2 pt1, Vector2 pt2)
{
    return (fabs(pt1.x - pt2.x) < Maths::Constants::epsilon && fabs(pt1.y - pt2.y) < Maths::Constants::epsilon);
}

inline bool Point_Line(Vector2 pt, Line line)
{
    Vector2 normal = Vector2::NormalVector(line.vectDir);
    Vector2 bP = { pt.x - line.base.x, pt.y - line.base.y };

    return (fabs(Vector2::DotProduct(bP, normal)) < Maths::Constants::epsilon);
}

inline bool Point_Segment(Vector2 pt, Segment seg) // check
{
    Line segLine = { pt, {seg.pt2.x - seg.pt1.x, seg.pt2.y - seg.pt1.y} };

    return (Point_Line(pt, segLine) == 0);
}

inline bool Point_Circle(Vector2 pt, Circle circle)
{
    Vector2 vect = { pt.x - circle.center.x, pt.y - circle.center.y };

    return (vect.SqrLength() <= circle.radius * circle.radius);
}

inline bool Point_Box(Vector2 pt, Rect box)
{
    return (pt.x <= box.center.x + box.halfWidth && pt.x >= box.center.x - box.halfWidth
            && pt.y <= box.center.y + box.halfHeight && pt.y >= box.center.y - box.halfHeight);
}