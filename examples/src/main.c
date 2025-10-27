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

		Vector2 mouse = GetMousePosition();

		float center_x = GetRenderWidth() / 2 / DPI;
		float center_y = GetRenderHeight() / 2 / DPI;

		int r1w = 10;
		int r1h = 10;

		int r2x = center_x - 50;
		int r2y = center_y - 50;
		int r2w = 100;
		int r2h = 100;

		int is_colliding = rectangle_rectangle(mouse.x, mouse.y, r1w, r1h, r2x, r2y, r2w, r2h);

		BeginDrawing();
		ClearBackground(BLACK);
		DrawRectangle(r2x, r2y, r2w, r2h, is_colliding ? BLUE : RED);
		DrawRectangle(mouse.x, mouse.y, r1w, r1h, RED);
		EndDrawing();
	}

	ShowCursor();
	CloseWindow();
	return 0;
}
