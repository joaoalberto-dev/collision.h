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
int point_rectangle(Point p, float rx, float ry, float rw, float rh);
int rectangle_rectangle(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h);

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

int point_rectangle(Point p, float rx, float ry, float rw, float rh)
{
    return (p.x > rx && p.x < rx + rw && p.y > ry && p.y < ry + rh);
}

int rectangle_rectangle(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h)
{
    return (r1x + r1w >= r2x && r1x <= r2x + r2w && r1y + r1h >= r2y && r1y <= r2y + r2h);
}

#endif
#endif
