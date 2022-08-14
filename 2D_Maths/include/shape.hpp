#pragma once

struct Vector2;


struct Segment
{
    Vector2 pt1, pt2;
};


struct Line
{
    Vector2 base, vectDir;

/**
 * @returns if there is a collision between two lines
 */
    bool Line_Line(Line line1, Line line2) const;

/**
 * @returns if there is a collision between a line and a segment
 */
    bool Line_Segment(Line line1, Segment seg) const;
};


struct Circle
{
    Vector2 center;
    float radius;

/**
 * @returns if there is a collision between two circles
 */
    bool Circle_Circle(Circle circle1, Circle circle2) const;
};


struct Rect
{
    Vector2 center;
    float halfHeight;
    float halfWidth;
};


struct OrientedRect
{
    Rect Rect;
    float angle;
};


struct ConvexPolygon
{
    Vector2* array_points;
};

/**
 * @returns if there is a collision between two points
 */
bool Point_Point(Vector2 pt1, Vector2 pt2);

/**
 * @returns if there is a collision between a point and a line
 */
bool Point_Line(Vector2 pt, Line line);

/**
 * @returns if there is a collision between a point and a segment
 */
bool Point_Segment(Vector2 pt, Segment seg); // check

/**
 * @returns if there is a collision between a point and a circle
 */
bool Point_Circle(Vector2 pt, Circle circle);

/**
 * @returns if there is a collision between a point and a box
 */
bool Point_Box(Vector2 pt, Rect box);


#include "shape.inl"