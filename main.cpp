#include <raylib.h>
int main(void)
{
    int sw = 960, sh = 720;
    InitWindow(sw, sh, "Collatz");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}