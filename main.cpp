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
    int sw = 960, sh = 720;
    InitWindow(sw, sh, "Collatz");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        for (int n = 2; n <= 2500; n++)
        {
            vector<int> seq = computeSequence(n);
            
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}