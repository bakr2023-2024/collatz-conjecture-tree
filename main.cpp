#include <raylib.h>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
using Segment = tuple<Vector2, Vector2, Color>;
vector<int> computeSequence(int n)
{
    vector<int> seq;
    while (n > 1)
    {
        seq.push_back(n);
        n = n % 2 == 0 ? n / 2 : (3 * n + 1) / 2;
    };
    reverse(seq.begin(), seq.end());
    return seq;
}
Color hexToRGB(unsigned long hex)
{
    return Color{
        (unsigned char)(hex >> 16 & 0xff),
        (unsigned char)(hex >> 8 & 0xff),
        (unsigned char)(hex & 0xff),
        255};
}
int main(int argc, char **argv)
{
    int branches = 2500;
    float thickness = 1.0f;
    Color backgroundColor = BLACK;
    Color branchesColor = WHITE;
    if (argc >= 5)
        thickness = stof(argv[4]);
    if (argc >= 4)
        branchesColor = hexToRGB(stoul(argv[3], nullptr, 0));
    if (argc >= 3)
        backgroundColor = hexToRGB(stoul(argv[2], nullptr, 0));
    if (argc >= 2)
        branches = stoi(argv[1]);
    float sw = 960, sh = 720;
    float turn = 0.08f;
    // movement vector represented as <0,-L> where L is line length, to move upwards
    float len = -7.0f;
    vector<Segment> segments;
    segments.reserve(10 * branches);
    for (int n = 2; n <= branches; n++)
    {
        Vector2 pos{sw / 4, sh};
        float θ = -M_PI_2;
        vector<int> seq = computeSequence(n);
        int size = seq.size();
        branchesColor.a = (unsigned char)(255 * size / 350.0f); // max number of steps for n < 100000 is 350 steps
        for (int i = 0; i < size - 1; i++)
        {
            θ = 2 * seq[i] == seq[i + 1] ? θ + 2 * turn : θ - turn;
            // apply rotation matrix to movement vector and add to pos vector to get newPos
            Vector2 newPos{pos.x - sinf(θ) * len, pos.y + cosf(θ) * len};
            segments.emplace_back(pos, newPos, branchesColor);
            pos = newPos;
        }
    }
    InitWindow(sw, sh, "Collatz Conjecture Tree");
    RenderTexture2D target = LoadRenderTexture(sw, sh);
    BeginTextureMode(target);
    ClearBackground(backgroundColor);
    for (auto &[a, b, c] : segments)
        DrawLineEx(a, b, thickness, c);
    EndTextureMode();
    segments.clear();
    segments.shrink_to_fit();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(backgroundColor);
        DrawTextureRec(target.texture,
                       {0, 0, sw, -sh},
                       {0, 0},
                       WHITE);
        EndDrawing();
    }
    UnloadRenderTexture(target);
    CloseWindow();
    return 0;
}