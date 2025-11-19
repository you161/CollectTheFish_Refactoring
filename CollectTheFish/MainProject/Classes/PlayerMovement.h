//
//playerMovement.h
//

#pragma once

#include "../HuEngine.h"

using namespace HE;
using namespace Math;

class PlayerMovement{
public:  
    Vector3 Movement(Vector3 position,Vector2 input,Vector2 size, float moveSpeedX, float moveSpeedY);
private:
};
