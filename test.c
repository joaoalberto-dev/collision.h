#define COLLISION_IMPLEMENTATION
#include "collision.h"
#include <stdio.h>
#include <assert.h>

void test_point_point(void)
{
    Point p1 = {.x = 1, .y = 1};
    Point p2 = {.x = 2, .y = 2};

    assert(point_point(p1, p1) == 1);
    assert(point_point(p1, p2) == 0);

    printf("✓ test_point_point passed\n");
}

void test_point_circle(void)
{
    Point p1 = {.x = 10, .y = 10};
    Point c1 = {.x = 100, .y = 100};
    int r1 = 10;

    Point p2 = {.x = 10, .y = 10};
    Point c2 = {.x = 15, .y = 15};
    int r2 = 20;

    assert(point_circle(p1, c1, r1) == 0);
    assert(point_circle(p2, c2, r2) == 1);

    printf("✓ test_point_circle passed\n");
}

int main(void)
{
    test_point_point();
    test_point_circle();
    printf("✓ All tests passed\n");
}
