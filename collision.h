#include <math.h>
#include <stddef.h>

#ifndef COLLISION_H
#define COLLISION_H

typedef struct Point
{
    float x;
    float y;
} Point;

int circle_circle(Point c1, float r1, Point c2, float r2);
int circle_line(float cx, float cy, float cr, Point l1, Point l2);
int circle_rectangle(float cx, float cy, float r, float rx, float ry, float rw, float rh);
int line_line(Point p1, Point p2, Point p3, Point p4);
int point_circle(Point p, Point c, float r);
int point_line(Point p1, Point p2, Point p3);
int point_point(Point p1, Point p2);
int point_rectangle(Point p, float rx, float ry, float rw, float rh);
int rectangle_rectangle(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h);

#ifdef COLLISION_IMPLEMENTATION

float calculate_distance(Point p1, Point p2)
{
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;

    return sqrt((dx * dx) + (dy * dy));
}

int circle_circle(Point c1, float r1, Point c2, float r2)
{
    float distX = c1.x - c2.x;
    float distY = c1.y - c2.y;
    float distance = sqrt((distX * distX) + (distY * distY));

    return (r1 + r2) > distance;
}

int circle_line(float cx, float cy, float cr, Point l1, Point l2)
{
    int start_inside_circle = point_circle(l1, (Point){.x = cx, .y = cy}, cr);
    int end_inside_circle = point_circle(l2, (Point){.x = cx, .y = cy}, cr);

    if (start_inside_circle || end_inside_circle)
    {
        return 1;
    }

    float size = calculate_distance(l1, l2);
    float dot = (((cx - l1.x) * (l2.x - l1.x)) + ((cy - l1.y) * (l2.y - l1.y)) / pow(size, 2));
    float closestX = l1.x + (dot * (l2.x - l1.x));
    float closestY = l1.y + (dot * (l2.y - l1.y));

    if (!point_line((Point){.x = closestX, .y = closestY}, l1, l2))
    {
        return 0;
    }

    float distX = closestX - cx;
    float distY = closestY - cy;
    float distance = sqrt((distX * distX) + (distY * distY));

    return distance <= cr;
}

int circle_rectangle(float cx, float cy, float r, float rx, float ry, float rw, float rh)
{
    int tx = cx;
    int ty = cy;

    if (cx < rx)
        tx = rx;
    if (cx > rx + rw)
        tx = rx + rw;

    if (cy < ry)
        ty = ry;
    if (cy > ry + rh)
        ty = ry + rh;

    float distX = cx - tx;
    float distY = cy - ty;
    float distance = sqrt((distX * distX) + (distY * distY));

    return distance <= r;
}

int line_line(Point p1, Point p2, Point p3, Point p4)
{
    float uA = ((p4.x - p3.x) * (p1.y - p3.y) - (p4.y - p3.y) * (p1.x - p3.x)) / ((p4.y - p3.y) * (p2.x - p1.x) - (p4.x - p3.x) * (p2.y - p1.y));
    float uB = ((p2.x - p1.x) * (p1.y - p3.y) - (p2.y - p1.y) * (p1.x - p3.x)) / ((p4.y - p3.y) * (p2.x - p1.x) - (p4.x - p3.x) * (p2.y - p1.y));

    return uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1;
}

int point_circle(Point p, Point c, float r)
{
    float distX = p.x - c.x;
    float distY = p.y - c.y;
    float distance = sqrt((distX * distX) + (distY * distY));

    return r > distance;
}

int point_line(Point c, Point p2, Point p3)
{
    float buffer = 0.01;
    float centerP2 = calculate_distance(c, p2);
    float centerP3 = calculate_distance(c, p3);
    float size = calculate_distance(p2, p3);

    return centerP2 + centerP3 >= size - buffer && centerP2 + centerP3 <= size + buffer;
}

int point_point(Point p1, Point p2)
{
    return p1.x == p2.x && p1.y == p2.y;
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
