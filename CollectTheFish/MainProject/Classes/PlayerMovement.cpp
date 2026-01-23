//
// PlayerMovement.cpp
//

#include "PlayerMovement.h"

Vector3 PlayerMovement::Movement(Vector3 position, Vector2 input,Vector2 size, float moveSpeedX, float moveSpeedY) {
	position.y += moveSpeedY * Time.deltaTime;
	position += input * moveSpeedX * Time.deltaTime;

	position.x = std::clamp(position.x, 0.0f, RenderingPath->GetLogicalWidth() - size.x);

	return position;
}