//
// FishMovement.cpp
//

#include "FishMovement.h"

using namespace HE;
using namespace Math;

void FishMovement::Movement(Vector3 position,Vector2 size,float speed,int move)
{
	position.x += speed * move * Time.deltaTime;
	if (move > 0) {
		if (position.x >= 1280.0f)
			position.x = -size.x;
	}
	else {
		if (position.x <= -size.x)
			position.x = 1280.0f + size.x;
	}
}