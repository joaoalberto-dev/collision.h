#define COLLISION_IMPLEMENTATION
#include "collision.h"
#include <stdio.h>
#include <assert.h>

void test_point_point(void)
{
    struct Point p1 = {.x = 1, .y = 1};
    struct Point p2 = {.x = 2, .y = 2};

    assert(point_point(p1, p1) == 1);
    assert(point_point(p1, p2) == 0);

    printf("✓ test_point_point passed\n");
}

int main(void)
{
    test_point_point();
    printf("✓ All tests passed\n");
}
