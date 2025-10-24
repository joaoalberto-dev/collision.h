#include "raylib.h"

int main()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(1280, 800, "Collision");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Collision", 0, 0, 20, WHITE);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
