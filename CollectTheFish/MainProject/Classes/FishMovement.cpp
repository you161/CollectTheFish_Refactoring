//
// FishMovement.cpp
//

#include "FishMovement.h"

using namespace HE;
using namespace Math;

Vector3 FishMovement::Movement(Vector3 position,Vector2 size,float speed,int move,Vector2 setPosition)
{
	position.x += speed * move * Time.deltaTime;
	if (move > 0) {
		if (position.x >= 1280.0f)
			position = setPosition;
	}
	else {
		if (position.x <= -size.x)
			position = setPosition;
	}

	return position;
}