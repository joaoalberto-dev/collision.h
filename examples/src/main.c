#include <stdio.h>
#include "raylib.h"

#define COLLISION_IMPLEMENTATION
#include "../../collision.h"

const int DPI = 2;

static inline Point to_point(struct Vector2 vec)
{
	return (Point){vec.x, vec.y};
}

int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
	InitWindow(1280, 800, "Collision");
	HideCursor();

	while (!WindowShouldClose())
	{

		float center_x = GetRenderWidth() / 2 / DPI;
		float center_y = GetRenderHeight() / 2 / DPI;
		Vector2 mouse = GetMousePosition();
		int rx = center_x - 50;
		int ry = center_y - 50;
		int rw = 100;
		int rh = 100;
		int is_colliding = point_rectangle(to_point(mouse), rx, ry, rw, rh);

		BeginDrawing();
		ClearBackground(BLACK);
		DrawRectangle(rx, ry, rw, rh, is_colliding ? BLUE : RED);
		DrawCircle(mouse.x, mouse.y, 1, RED);
		EndDrawing();
	}

	ShowCursor();
	CloseWindow();
	return 0;
}
