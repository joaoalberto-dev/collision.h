#include <stdio.h>
#include "raylib.h"

#define COLLISION_IMPLEMENTATION
#include "../../collision.h"

const int DPI = 2;

static inline Point toPoint(struct Vector2 vec)
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

		float centerX = GetRenderWidth() / 2 / DPI;
		float centerY = GetRenderHeight() / 2 / DPI;

		Vector2 mouse = GetMousePosition();
		int is_colliding = point_point(toPoint(mouse), (Point){.x = centerX, .y = centerY});

		BeginDrawing();
		ClearBackground(BLACK);
		DrawCircle(centerX, centerY, 10, RED);
		DrawCircle(mouse.x, mouse.y, 10, is_colliding ? BLUE : RED);
		EndDrawing();
	}

	ShowCursor();
	CloseWindow();
	return 0;
}
