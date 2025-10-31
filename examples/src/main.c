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

		Vector2 l1 = {.x = center_x, .y = 100};
		Vector2 l2 = {.x = center_x, .y = (center_y * 2) - 100};

		int is_colliding = circle_line(mouse.x, mouse.y, 10, to_point(l1), to_point(l2));

		BeginDrawing();
		ClearBackground(BLACK);
		DrawLine(l1.x, l1.y, l2.x, l2.y, is_colliding ? BLUE : RED);
		DrawCircle(mouse.x, mouse.y, 10, is_colliding ? BLUE : RED);
		EndDrawing();
	}

	ShowCursor();
	CloseWindow();
	return 0;
}
