#ifndef COLLISION_H
#define COLLISION_H
#ifdef __cpluplus
extern "C"
#endif

    int point_point(int p1_x, int p1_y, int p2_x, int p2_y);

#ifdef COLLISION_IMPLEMENTATION

int point_point(int p1_x, int p1_y, int p2_x, int p2_y)
{
    return p1_x == p2_x && p1_y == p2_y;
}

#endif

#ifdef __cplusplus
#endif
#endif
