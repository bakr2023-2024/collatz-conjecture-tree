#include <raylib.h>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
vector<int> computeSequence(int n)
{
    vector<int> seq;
    seq.push_back(1);
    while (n > 1)
    {
        seq.push_back(n);
        n = n % 2 == 0 ? n / 2 : (3 * n + 1) / 2;
    };
    return seq;
}
int main(void)
{
    float sw = 960, sh = 720;
    float turn = 0.08f;
    // movement vector represented as <0,-L> where L is line length, to move upwards
    float len = -5.0f;
    InitWindow(sw, sh, "Collatz");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        for (int n = 2; n <= 2500; n++)
        {
            vector<int> seq = computeSequence(n);
            Vector2 pos{sw / 2, sh / 2};
            float θ = 0.0f;
            for (int i = 1; i < seq.size() - 1; i++)
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