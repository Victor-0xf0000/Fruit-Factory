#include <Core/Math/MathHelper.h>

bool isPointOnBox(int x, int y, int bx, int by, int bw, int bh)
{
    return x > bx && x < bx + bw && y > by && y < by + bh;
}