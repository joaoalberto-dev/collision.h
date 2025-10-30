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
		Vector2 scale = GetWindowScaleDPI();
		float finalScale = scale.x ? scale.x : DPI;

		float center_x = GetRenderWidth() / 2 / finalScale;
		float center_y = GetRenderHeight() / 2 / finalScale;

		int r2x = center_x - 50;
		int r2y = center_y - 50;
		int r2w = 100;
		int r2h = 100;

		int is_colliding = circle_rectangle(mouse.x, mouse.y, 10, 0, 0, 100, 100);

		BeginDrawing();
		ClearBackground(BLACK);
		DrawRectangle(0, 0, 100, 100, is_colliding ? BLUE : RED);
		DrawCircle(mouse.x, mouse.y, 10, RED);
		EndDrawing();
	}

	ShowCursor();
	CloseWindow();
	return 0;
}
