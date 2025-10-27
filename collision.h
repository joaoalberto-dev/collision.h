#include <math.h>

#ifndef COLLISION_H
#define COLLISION_H

typedef struct Point
{
    float x;
    float y;
} Point;

int point_point(Point p1, Point p2);
int point_circle(Point p, Point c, float r);
int circle_circle(Point c1, float r1, Point c2, float r2);

#ifdef COLLISION_IMPLEMENTATION

int point_point(Point p1, Point p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

int point_circle(Point p, Point c, float r)
{
    float distX = p.x - c.x;
    float distY = p.y - c.y;
    float distance = sqrt((distX * distX) + (distY * distY));

    return r > distance;
}

int circle_circle(Point c1, float r1, Point c2, float r2)
{
    float distX = c1.x - c2.x;
    float distY = c1.y - c2.y;
    float distance = sqrt((distX * distX) + (distY * distY));

    return (r1 + r2) > distance;
}

#endif
#endif
