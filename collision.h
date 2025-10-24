#ifndef COLLISION_H
#define COLLISION_H

typedef struct Point
{
    float x;
    float y;
} Point;

int point_point(Point p1, Point p2);

#ifdef COLLISION_IMPLEMENTATION

int point_point(Point p1, Point p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

#endif
#endif
