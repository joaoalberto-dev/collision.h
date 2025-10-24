#ifndef COLLISION_H
#define COLLISION_H

int point_point(int x1, int y1, int x2, int y2);

#ifdef COLLISION_IMPLEMENTATION

int point_point(int x1, int y1, int x2, int y2)
{
    return x1 == x2 && y1 == y2;
}

#endif
#endif
