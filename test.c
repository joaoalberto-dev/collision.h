#define COLLISION_IMPLEMENTATION
#include "collision.h"
#include <stdio.h>
#include <assert.h>

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

void pass_message(char *msg)
{
    printf(ANSI_COLOR_GREEN "✓" ANSI_COLOR_RESET " test_%s" ANSI_COLOR_GREEN " passed\n" ANSI_COLOR_RESET, msg);
}

void test_circle_circle(void)
{
    Point c1 = {.x = 10, .y = 10};
    Point c2 = {.x = 50, .y = 50};
    Point c3 = {.x = 20, .y = 20};

    assert(circle_circle(c1, 10, c2, 10) == 0);
    assert(circle_circle(c1, 10, c3, 10) == 1);

    pass_message("circle_circle");
}

void test_circle_rectangle(void)
{

    assert(circle_rectangle(10, 10, 10, 50, 50, 10, 10) == 0);
    assert(circle_rectangle(10, 10, 10, 15, 15, 10, 10) == 1);

    pass_message("circle_rectangle");
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

    pass_message("point_circle");
}

void test_point_line(void)
{
    Point c1 = {.x = 11, .y = 5};
    Point c2 = {.x = 10, .y = 5};
    Point l1 = {.x = 10, .y = 0};
    Point l2 = {.x = 10, .y = 10};

    assert(point_line(c1, l1, l2) == 0);
    assert(point_line(c2, l1, l2) == 1);

    pass_message("point_line");
}

void test_point_point(void)
{
    Point p1 = {.x = 1, .y = 1};
    Point p2 = {.x = 2, .y = 2};

    assert(point_point(p1, p1) == 1);
    assert(point_point(p1, p2) == 0);

    pass_message("point_point");
}

void test_point_rectangle(void)
{
    Point p = {.x = 10, .y = 10};

    assert(point_rectangle(p, 20, 20, 10, 10) == 0);
    assert(point_rectangle(p, 5, 5, 10, 10) == 1);

    pass_message("point_rectangle");
}

void test_rectangle_rectangle(void)
{

    assert(rectangle_rectangle(0, 0, 10, 10, 20, 20, 10, 10) == 0);
    assert(rectangle_rectangle(15, 15, 10, 10, 20, 20, 10, 10) == 1);

    pass_message("rectangle_rectangle");
}

int main(void)
{
    test_circle_circle();
    test_circle_rectangle();
    test_point_circle();
    test_point_line();
    test_point_point();
    test_point_rectangle();
    test_rectangle_rectangle();
}
