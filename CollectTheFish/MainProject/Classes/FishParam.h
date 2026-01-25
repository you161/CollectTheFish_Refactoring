#pragma once
#include "../HuEngine.h"

using namespace HE;
using namespace Math;
using namespace std;

struct FishParam
{
    string sprite;
    Vector2 drawSize;
    float speed;
    int direction;
    int score;
    Vector2 spawnPos;
    bool resetOnHit;
};
