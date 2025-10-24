#define COLLISION_IMPLEMENTATION
#include "collision.h"
#include <stdio.h>
#include <assert.h>

void test_point_point(void)
{
    assert(point_point(1, 1, 1, 1) == 1);
    assert(point_point(1, 1, 2, 2) == 0);
    printf("✓ test_point_point passed\n");
}

int main(void)
{
    test_point_point();
    printf("✓ All tests passed\n");
}
