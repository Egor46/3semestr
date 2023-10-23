#include "BoolFunction.h"

BoolFunction::BoolFunction(bool x[4]) {
    for (int i = 0; i < 4; i++)xd[i] = x[i];
}

BoolFunction BoolFunction::AND(BoolFunction b)
{
    bool x[4] = { xd[0] && b.xd[0], xd[1] && b.xd[1], xd[2] && b.xd[2], xd[3] && b.xd[3] };
    return BoolFunction(x);
}

BoolFunction BoolFunction::OR(BoolFunction b)
{
    bool x[4] = { xd[0] || b.xd[0], xd[1] || b.xd[1], xd[2] || b.xd[2], xd[3] || b.xd[3] };
    return BoolFunction(x);
}

void BoolFunction::NOT()
{
    for (int i = 0; i < 4; i++) xd[i] = !xd[i];
}

bool BoolFunction::func(bool a, bool b) {
    return xd[a*2+b];
}
