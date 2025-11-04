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

		Vector2 p1 = {.x = center_x, .y = 100};
		Vector2 p2 = {.x = center_x, .y = (center_y * 2) - 100};
		Vector2 p3 = {.x = 100, .y = center_y - 100};
		Vector2 p4 = {.x = mouse.x, .y = mouse.y};

		int is_colliding = line_line(to_point(p1), to_point(p2), to_point(p3), to_point(p4));

		BeginDrawing();
		ClearBackground(BLACK);
		DrawLine(p1.x, p1.y, p2.x, p2.y, is_colliding ? BLUE : RED);
		DrawLine(p3.x, p3.y, p4.x, p4.y, is_colliding ? BLUE : RED);
		EndDrawing();
	}

	ShowCursor();
	CloseWindow();
	return 0;
}
