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

#endif
#endif
