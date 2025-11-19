//
//FishMovement.h
//

#pragma once

#include "../HuEngine.h"

using namespace HE;
using namespace Math;
using std::string;

class FishMovement {
public:
	Vector3 Movement(Vector3 position, Vector2 size,float speed,int move,Vector2 setPosition);
protected:
};