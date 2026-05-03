#include <raylib.h>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;
vector<int> computeSequence(int n)
{
    vector<int> seq;
    while (n > 1)
    {
        seq.emplace(seq.begin(), n);
        n = n % 2 == 0 ? n / 2 : (3 * n + 1) / 2;
    };
    return seq;
}
int main(void)
{
    float sw = 960, sh = 720;
    float turn = 0.08f;
    // movement vector represented as <0,-L> where L is line length, to move upwards
    float len = -7.0f;
    InitWindow(sw, sh, "Collatz");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        for (int n = 2; n <= 2500; n++)
        {
            vector<int> seq = computeSequence(n);
            Vector2 pos{sw / 4, sh * 0.9f};
            float θ = -M_PI_2;
            for (int i = 0; i < seq.size() - 1; i++)
            {
                θ = 2 * seq[i] == seq[i + 1] ? θ + 2 * turn : θ - turn;
                // apply rotation matrix to movement vector and add to pos vector to get newPos
                Vector2 newPos{pos.x - sinf(θ) * len, pos.y + cosf(θ) * len};
                DrawLineV(pos, newPos, WHITE);
                pos = newPos;
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}