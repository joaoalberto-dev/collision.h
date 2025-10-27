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

void test_circle_circle(void)
{
    Point c1 = {.x = 10, .y = 10};
    Point c2 = {.x = 50, .y = 50};
    Point c3 = {.x = 20, .y = 20};

    assert(circle_circle(c1, 10, c2, 10) == 0);
    assert(circle_circle(c1, 10, c3, 10) == 1);

    printf("✓ test_circle_circle passed\n");
}

void test_point_rectangle(void)
{
    Point p = {.x = 10, .y = 10};

    assert(point_rectangle(p, 20, 20, 10, 10) == 0);
    assert(point_rectangle(p, 5, 5, 10, 10) == 1);

    printf("✓ test_point_rectangle passed\n");
}

void test_rectangle_rectangle(void)
{

    assert(rectangle_rectangle(0, 0, 10, 10, 20, 20, 10, 10) == 0);
    assert(rectangle_rectangle(15, 15, 10, 10, 20, 20, 10, 10) == 1);

    printf("✓ test_rectangle_rectangle passed\n");
}

int main(void)
{
    test_point_point();
    test_point_circle();
    test_circle_circle();
    test_point_rectangle();
    test_rectangle_rectangle();

    printf("✓ All tests passed\n");
}
